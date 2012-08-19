/*
 * SAutorization.hpp
 *
 *  Created on: 19.08.2012
 *      Author: andrey
 */

#ifndef SAUTORIZATION_HPP_
#define SAUTORIZATION_HPP_

class SAutorization
{
public:
	SAutorization();
	virtual ~SAutorization();

	int sessionLifeTime;
	char sessions[5];

	void createSession();
	bool sessionValidate();
};

#endif /* SAUTORIZATION_HPP_ */
