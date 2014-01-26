/*
 * PacketFactory.h
 *
 *  Created on: 2014年1月23日
 *      Author: tmdjojo
 */

#ifndef PACKETFACTORY_H_
#define PACKETFACTORY_H_
#include "./Packet.h"
#include "../Type.h"

typedef Packet*(*PacketCreateMethord)(PacketHead&,const char*);
#define PACKETCREATER(DerivedPacket,ProtcolMessage) \
class DerivedPacket##Creater{\
public:\
    static Packet* Create(PacketHead& head,const char* data){\
        DerivedPacket* pkt = new DerivedPacket(head);\
        do{\
            if(NULL == pkt)break;\
            ProtcolMessage msg = new ProtcolMessage;\
            if(NULL == msg){\
                SAFE_DELETE(pkt);break;\
            }\
            if(!msg->ParseFromArray(data,head.data_length_)){\
                SAFE_DELETE(pkt);\
                SAFE_DELETE(msg);\
                break;\
            }\
            pkt->set_message(msg);\
        }while(0);\
    }\
    return ptk;\
};



enum PacketType{
    ERRORTYPE       = -1,

    COUNT
};

class PacketFactory {
public:
    PacketFactory();
    virtual ~PacketFactory();
    static Packet* Create(PacketHead&,const char*);
};

#endif /* PACKETFACTORY_H_ */
