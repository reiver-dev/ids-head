#include "Config.h"
#include <iostream>

Config::Config(const char *cfg_file)
{
	try {
		file.readFile((cfg_file ? cfg_file : "config.cfg"));
	}
	catch (const libconfig::FileIOException &fioex)
	{
		std::cerr << "I/O error while reading file. (config.cfg)";
		exit (EXIT_FAILURE);
	}
	catch(const libconfig::ParseException &pex)
	{
		std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
		exit (EXIT_FAILURE);
	}
	
	const libconfig::Setting &config_root = file.getRoot();
	
	const libconfig::Setting &config_app          = config_root["app"];
	const libconfig::Setting &config_dump_listner = config_root["dump_listner"];
	const libconfig::Setting &config_db           = config_root["db"];
	
	// App config
	if(!config_app.lookupValue("log_file", this->log_file)) {
		this->log_file = "log.txt";
	}
	config_app.lookupValue("debug", this->debug);
	
	// DumpLisn config
	config_dump_listner.lookupValue("protocol", this->dump_lisn.protocol);
	config_dump_listner.lookupValue("ip", this->dump_lisn.ip);
	config_dump_listner.lookupValue("port", this->dump_lisn.port);
	
	// DB config
	config_db.lookupValue("ip", this->db.ip);
	config_db.lookupValue("port", this->db.port);
	config_db.lookupValue("db_name", this->db.db_name);
	config_db.lookupValue("dump_collection", this->db.dump_collection);
}