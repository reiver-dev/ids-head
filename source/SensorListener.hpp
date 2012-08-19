/*
 * SensorListener.hpp
 *
 *  Created on: 19.08.2012
 *      Author: andrey
 */

#ifndef SENSORLISTENER_HPP_
#define SENSORLISTENER_HPP_

class SensorListener
{
public:
	SensorListener();
	virtual ~SensorListener();

	int port;
	char message[5];
	void startListen();
	void stopListen();
	void receiveMessage();
	void sendMessage();
};

#endif /* SENSORLISTENER_HPP_ */
