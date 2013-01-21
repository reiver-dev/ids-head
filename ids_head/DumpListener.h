#ifndef __ids_head__DumpListener__
#define __ids_head__DumpListener__

#include "Config.h"
#include <boost/thread.hpp>
#include <zmq.hpp>

class DumpListener {
public:
	DumpListener(struct dump_lisn_cfg *dlc_, class MongoDB *db_);
	
	void wait();
	void stop();
	
private:
	zmq::context_t context;
	zmq::socket_t clients;
	zmq::socket_t workers;
	
	struct dump_lisn_cfg *config;
	class MongoDB *db;
	
	static void start(void *arg);
	
	boost::thread starter;
};

#endif /* defined(__ids_head__DumpListener__) */
