/*
 * DumpListener.hpp
 *
 *  Created on: 19.08.2012
 *      Author: andrey
 */

#ifndef DUMPLISTENER_HPP_
#define DUMPLISTENER_HPP_

#include "Reciver.hpp"

class DumpListener
{
public:
	DumpListener();
	virtual ~DumpListener();

	int port;
	Reciver reciver;

	void startListen();
	void stopListen();
	int getActiveSensorCount();
	void manageReciver();

};

#endif /* DUMPLISTENER_HPP_ */
