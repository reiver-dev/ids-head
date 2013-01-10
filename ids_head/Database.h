#ifndef __ids_head__Database__
#define __ids_head__Database__

class DB {
public:
	static void dump(struct db_cfg *dbc, int tv_sec, int tv_usec, int caplen, int len);
};

#endif /* defined(__ids_head__Database__) */
