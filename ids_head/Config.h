#ifndef __ids_head__Config__
#define __ids_head__Config__

#include <libconfig.h++>

struct dump_lisn_cfg {
	const char *protocol;
	const char *ip;
	
	int port;
};

struct db_cfg {
	const char *ip;
	int port;
	
	const char *db_name;
	const char *dump_collection;
};

class Config {	
public:
	Config(const char *cfg_file);
	
	const char *log_file;
	bool debug;
	
	dump_lisn_cfg dump_lisn;
	db_cfg db;
	
private:
	libconfig::Config file;
};

#endif /* defined(__ids_head__Config__) */
