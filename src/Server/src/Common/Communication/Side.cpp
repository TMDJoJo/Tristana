/*
 * Side.cpp
 *
 *  Created on: 2014年1月23日
 *      Author: tmdjojo
 */

#include "Side.h"

Side::Side():
socket_(NULL)
{
    // TODO Auto-generated constructor stub

}

Side::~Side() {
    // TODO Auto-generated destructor stub
}

INT Side::SendPacket(Packet* packet){
    return output_buffer_.EncodeMessage(packet);
}

Packet* Side::ReceivePacket(){
    return input_buffer_.DecodeMessage();
}

BOOL Side::Input(){
    INT re = input_buffer_.ReadSocket(socket_);

    return TRUE;
}

BOOL Side::Output(){

    return TRUE;
}
