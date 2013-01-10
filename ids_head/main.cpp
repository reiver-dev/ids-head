//
//  main.cpp
//  ids_head
//

#include <libconfig.h++>
#include "Config.h"
#include "Database.h"
#include "DumpListener.h"

#include <iostream>

int main(int argc, const char * argv[])
{
	Config cfg;
	cfg.read_cfg(argv[1]);
	
	db_cfg dbc;
	cfg.get_db_cfg(&dbc);
	
	DB db;
	db.connect(&dbc);
	
	dump_lisn_cfg dlc;
	cfg.get_dump_lisn_cfg(&dlc);
	
	dump_listner DumpLisn;
	DumpLisn.start(&dlc);
	
	return 0;
}