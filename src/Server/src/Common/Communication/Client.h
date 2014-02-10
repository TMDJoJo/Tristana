/*
 * Client.h
 *
 *  Created on: 2014年1月24日
 *      Author: tmdjojo
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Side.h"

class Client: public Side {
public:
	Client();
	virtual INT Execute();
	virtual ~Client();
};

#endif /* CLIENT_H_ */
