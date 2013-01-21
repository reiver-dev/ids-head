#ifndef __ids_head__Core__
#define __ids_head__Core__

#include "Config.h"
#include "Database.h"
#include "DumpListener.h"

#include <signal.h>
#include <sys/stat.h>
#include <logog/logog.hpp>
#include <iostream>

class Monitor {
public:
	Monitor(const char *argv[]);
	int start();
	static void stop(int exit_code);
	
	void SetPidFile(int pid);
	int GetPidFile();
	
private:
	const char *config_file;
	int pid;
};

#endif /* defined(__ids_head__Core__) */
