#include "Database.h"
#include <mongo/client/dbclient.h>


MongoDB::MongoDB(struct db_cfg *dbc) {
	this->dbc = dbc;
	
	INFO("[Database] Configured...");
}

void MongoDB::dump(int tv_sec, int tv_usec, int caplen, int len) {
	
	char addr[255];
	sprintf(addr, "%s:%d", dbc->ip, dbc->port);
	
	char collection[255];
	sprintf(collection, "%s,%s", dbc->db_name, dbc->dump_collection);
	
	try {
		boost::scoped_ptr<mongo::ScopedDbConnection> conn(mongo::ScopedDbConnection::getScopedDbConnection(addr));
			
		mongo::BSONObj headers = BSON(mongo::GENOID << "tv_sec" << tv_sec << "tv_usec" << tv_usec << "caplen" << caplen << "len" << len);
		conn->get()->insert(collection, headers);
		
		conn->done();
		
		INFO("[Database] Insert dump to %s", collection);
		
	} catch( const mongo::DBException &e ) {
		ERR("[Database] Dump exception: %s", e.what());
	}
}