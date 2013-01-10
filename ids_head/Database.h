#ifndef __ids_head__Database__
#define __ids_head__Database__

class DB {
public:
	void connect(struct db_cfg *dbc);
	static void dump(int tv_sec, int tv_usec, int caplen, int len);
};

#endif /* defined(__ids_head__Database__) */
