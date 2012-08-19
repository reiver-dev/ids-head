/*
 * reciver.hpp
 *
 *  Created on: 19.08.2012
 *      Author: andrey
 */

#ifndef RECIVER_HPP_
#define RECIVER_HPP_

class Reciver
{
public:
	char sessionHash[5];
	char sessionKey[5];

	Reciver();
	virtual ~Reciver();
	void parseSession ();
};

#endif /* RECIVER_HPP_ */
