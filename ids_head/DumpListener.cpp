#include "DumpListener.h"
#include "Config.h"
#include "Database.h"
#include "STrafficManager.h"

#include <iostream>

#include <pcap.h>
#include <boost/thread.hpp>
#include <zmq.hpp>
#include <msgpack.hpp>

struct dump_headers {
	int tv_sec;
	int tv_usec;
	int caplen;
	int len;
	
	MSGPACK_DEFINE(tv_sec, tv_usec, caplen, len);
};

void worker(zmq::context_t& context)
{
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
				
				DB::dump(headers.tv_sec, headers.tv_usec, headers.caplen, headers.len);
				
				pac.next(&result);
				// Data: result.get()
			}
		}
	}
	catch(const zmq::error_t& ze)
	{
		std::cout << "Worker exception: " << ze.what() << std::endl;
	}
}

void dump_listner::start(struct dump_lisn_cfg *dlc)
{
	boost::thread_group threads;
	try
	{
		zmq::context_t context(1);
		zmq::socket_t clients(context, ZMQ_PULL);
		
		char addr[255];
		sprintf(addr, "%s://%s:%d", dlc->protocol, dlc->ip, dlc->port);
		clients.bind(addr);
		
		zmq::socket_t workers(context, ZMQ_PUSH);
		workers.bind("inproc://workers");
		
		for(int i=0;i<4;i++)
			threads.create_thread(bind(worker, boost::ref(context)));
		
		zmq::device(ZMQ_STREAMER, clients, workers);
	}
	catch(const zmq::error_t& ze)
	{
		std::cout << "Listner exception: " << ze.what() << std::endl;
	}
}
