#ifndef __ids_head__Database__
#define __ids_head__Database__

#include "Config.h"
#include <logog/logog.hpp>

class MongoDB {
public:
	MongoDB(struct db_cfg *dbc);
	void dump(int tv_sec, int tv_usec, int caplen, int len);
	
private:
	struct db_cfg *dbc;
};

#endif /* defined(__ids_head__Database__) */
