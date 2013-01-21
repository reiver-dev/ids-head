#include "DumpListener.h"
#include "Database.h"
#include "STrafficManager.h"

#include <iostream>

#include <msgpack.hpp>
#include <logog/logog.hpp>

struct dump_headers {
	int tv_sec;
	int tv_usec;
	int caplen;
	int len;
	
	MSGPACK_DEFINE(tv_sec, tv_usec, caplen, len);
};

void worker(zmq::context_t &context, class MongoDB *db) {
	
	dump_headers headers;
	
	try
	{
		zmq::socket_t socket(context, ZMQ_PULL);
		socket.connect("inproc://workers");

		while(true)
		{
			zmq::message_t request;
			socket.recv(&request);
			
			msgpack::unpacker pac;
			
			pac.reserve_buffer(request.size());
			memcpy(pac.buffer(), request.data(), request.size());
			pac.buffer_consumed(request.size());
			
			msgpack::unpacked result;
			
			while (pac.next(&result)) {
				headers = result.get().as<dump_headers>();
				
				db->dump(headers.tv_sec, headers.tv_usec, headers.caplen, headers.len);
			
				pac.next(&result);
				// Data: result.get()
			}
		}
	}
	catch(const zmq::error_t& ze)
	{
		ERR("[DumpListener] Worker exception: %s", ze.what());
	}
}

void DumpListener::start(void *arg) {
	
	INFO("[DumpListener] Starting...");
	
	DumpListener *self = static_cast<DumpListener *>(arg);
	
	zmq_proxy(self->clients, self->workers, NULL);
}

void DumpListener::wait() {
	
	starter.join();
}

void DumpListener::stop() {
	
	context.close();
}

DumpListener::DumpListener(struct dump_lisn_cfg *dlc_, class MongoDB *db_)
:	context(1)
,	clients(context, ZMQ_PULL)
,	workers(context, ZMQ_PUSH)
{
	config = dlc_;
	db = db_;
	
	boost::thread_group threads;
	
	try
	{
		char addr[255];
		sprintf(addr, "%s://%s:%d", config->protocol, config->ip, config->port);
		clients.bind(addr);
		
		workers.bind("inproc://workers");
		
		for(int i=0;i<4;i++) {
			threads.create_thread(boost::bind(worker, boost::ref(context), db));
			
			INFO("[DumpListener] Thread %d created", i+1);
		}
		starter = boost::thread(boost::bind(start, this));
		
	}
	catch(const zmq::error_t& ze)
	{
		ERR("[DumpListener] Listner exception: %s", ze.what());
	}
}