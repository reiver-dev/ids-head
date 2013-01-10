#include "Config.h"
#include <iostream>

void Config::read_cfg(const char * cfg_file) {
	
	try {
		file.readFile((cfg_file ? cfg_file : "cfg_file"));
	}
	catch (const libconfig::FileIOException &fioex)
	{
		std::cerr << "I/O error while reading file. (config.cfg)";
		exit (EXIT_FAILURE);
	}
	catch(const libconfig::ParseException &pex)
	{
		std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
		<< " - " << pex.getError() << std::endl;
		exit (EXIT_FAILURE);
	}
	
};

void Config::get_dump_lisn_cfg(struct dump_lisn_cfg *dlc) {
	
	const libconfig::Setting &config = file.getRoot();
	const libconfig::Setting &config_dump_listner = config["dump_listner"];
	
	config_dump_listner.lookupValue("protocol", dlc->protocol);
	config_dump_listner.lookupValue("ip", dlc->ip);
	config_dump_listner.lookupValue("port", dlc->port);
}
	
void Config::get_db_cfg(struct db_cfg *dbc) {

	const libconfig::Setting &config = file.getRoot();
	const libconfig::Setting &config_db = config["db"];

	config_db.lookupValue("ip", dbc->ip);
	config_db.lookupValue("port", dbc->port);
}