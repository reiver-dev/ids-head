#include "Core.h"

void Monitor::stop(int exit_code) {
	
	INFO("[Monitor] IDS Demon shutdown");
	
	LOGOG_SHUTDOWN();
	
	exit(exit_code);
}

void Monitor::SetPidFile(int pid) {
	FILE *f;
	
	f = fopen(".ids_head.pid", "w+");
	
	if (f) {
		fprintf(f, "%u", pid);
		fclose(f);
	} else {
		ERR("[Monitor] Error save .pid file");
		exit(EXIT_FAILURE);
	}
}

int Monitor::GetPidFile() {
	FILE *f;
	pid = 0;
	
	f = fopen(".ids_head.pid", "r+");
	
	if (f) {
		fscanf(f, "%d", &pid);
		fclose(f);
		
		return pid;
	} else {
		ERR("[Monitor] Error read .pid file");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}

Monitor::Monitor(const char *argv[]) {
	std::string key = argv[1];
	
	if(key == "stop") {
		kill(GetPidFile(), SIGTERM);
		
		exit(0);
	} else {
		config_file = argv[1];
	}
	
}

int Monitor::start() {
	
	signal(SIGTERM, stop);
	
	Config config(this->config_file);
	
	pid = fork();
	
	if (pid == -1) {
		
		ERR("[Monitor] Start IDS Daemon failed (%s)\n", strerror(errno));
		
		return -1;
		
	} else if(!pid) {
		
		SetPidFile(getpid());

		umask(0);
		setsid();
		
		if(!config.debug) {
			close(STDIN_FILENO);
			close(STDOUT_FILENO);
			close(STDERR_FILENO);
		}
		
		LOGOG_INITIALIZE();
		
		{
			
			logog::LogFile errFile(config.log_file);
			
			INFO("[Monitor] IDS Demon starting...");
			
			MongoDB db(&config.db);
			
			DumpListener DumpLisn(&config.dump_lisn, &db);
			
			DumpLisn.wait();
		}
		
		LOGOG_SHUTDOWN();
		
		
		return 0;
		
	} else {

		return 0;
	}
}