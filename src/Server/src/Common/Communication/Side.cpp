/*
 * Side.cpp
 *
 *  Created on: 2014.1.23
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

    return (0 == re);
}

BOOL Side::Output(){
    INT re = output_buffer_.WriteSocket(socket_);

    return (0 == re);

}
