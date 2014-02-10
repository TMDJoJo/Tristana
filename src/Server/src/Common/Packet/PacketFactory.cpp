/*
 * PacketFactory.cpp
 *
 *  Created on: 2014.1.23
 *      Author: tmdjojo
 */

#include "PacketFactory.h"

PacketCreateMethord PacketCreateMethordList[] = {
        NULL
};

PacketFactory::PacketFactory() {
    // TODO Auto-generated constructor stub

}

PacketFactory::~PacketFactory() {
    // TODO Auto-generated destructor stub
}

Packet* PacketFactory::Create(PacketHead& head,const char* data){
    if(head.packet_type_ > COUNT
            ||head.packet_type_ < ERRORTYPE){
        return NULL;
    }
    return PacketCreateMethordList[head.packet_type_](head,data);
}
