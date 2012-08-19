#include <iostream>
#include "Core.hpp"
#include "DumpListener.hpp"
#include "Reciver.hpp"
#include "SAutorization.hpp"
#include "SensorListener.hpp"
#include "SLoging.hpp"
#include "STrafficManager.hpp"



int main ()
{
	Core core;
	core.loadConfig();
	core.initLogging();
	core.initSubSystems();

	core.linkClients();
	core.initListeners();
	core.linkListeners();
	core.startListeners();


	int i=5;

	std::cin >>i;
	system("pause");
	return 0;
}

