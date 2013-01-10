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
};

class Config {
private:
	libconfig::Config file;
	
public:
	void read_cfg(const char * cfg_file);
	void get_dump_lisn_cfg(struct dump_lisn_cfg *dlc);
	void get_db_cfg(struct db_cfg *dbc);
};

#endif /* defined(__ids_head__Config__) */
