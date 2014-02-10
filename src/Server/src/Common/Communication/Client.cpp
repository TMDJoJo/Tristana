/*
 * Client.cpp
 *
 *  Created on: 2014年1月24日
 *      Author: tmdjojo
 */

#include "Client.h"

Client::Client() {
	// TODO Auto-generated constructor stub

}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

INT Client::Execute(){
    Packet* packet = this->ReceivePacket();
    if(NULL == packet)
        return 0;
    return packet->Execute(this);
}
