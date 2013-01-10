#include <mongo/client/dbclient.h>
#include <cstdlib>
#include <iostream>
#include "Config.h"
#include "Database.h"

void DB::connect(struct db_cfg *dbc) {
	
	char addr[255];
	sprintf(addr, "%s:%d", dbc->ip, dbc->port);
	
	try {
		mongo::DBConnectionPool pool;
		pool.get(addr);
	} catch( const mongo::DBException &e ) {
		std::cout << "DB: " << e.what() << std::endl;
	}
}

void DB::dump(int tv_sec, int tv_usec, int caplen, int len) {
	try {
		boost::scoped_ptr<mongo::ScopedDbConnection> conn(mongo::ScopedDbConnection::getScopedDbConnection("localhost"));
		
		mongo::BSONObj headers = BSON(mongo::GENOID << "tv_sec" << tv_sec << "tv_usec" << tv_usec << "caplen" << caplen << "len" << len);
		conn->get()->insert("ids.dump", headers);
		
		conn->done();
		
	} catch( const mongo::DBException &e ) {
		std::cout << "DB: " << e.what() << std::endl;
	}
}