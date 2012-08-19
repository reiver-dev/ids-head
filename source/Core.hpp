/*
 * Core.hpp
 *
 *  Created on: 19.08.2012
 *      Author: andrey
 */

#ifndef CORE_HPP_
#define CORE_HPP_

class Core
{
public:
	Core();
	virtual ~Core();

	int logger;
		int	config;

		void loadConfig ();
			void initLogging();
			void initSubSystems();
			void initListeners();
			void linkClients();
			void linkListeners();
			void linkSubSystems();
			void startListeners();
};

#endif /* CORE_HPP_ */


