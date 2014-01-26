/*
 * Copyright (C) 2013-2014 Project_H. All rights reserved.
 *
 * Language: UTF-8
 * Maximum line width: 80 chars
 * Tab width: 4 spaces
 *
 *  File name: Packet.h
 *  Created on: 2014-1-1
 *  Author: tmdjojo
 *  Description:
 */

#ifndef PACKET_H_
#define PACKET_H_
#include <google/protobuf/message.h>
#include "../Type.h"

class Side;

struct PacketHead_T{
    INT packet_type_;
    INT data_length_;
    INT crc32_;
    PacketHead_T(){
        packet_type_ = -1;
        data_length_ = 0;
        crc32_ = 0;
    };
    PacketHead_T(int type,int len){
        packet_type_ = type;
        data_length_ = len;
        crc32_ = 0;
    };
};
typedef struct PacketHead_T PacketHead;

class Packet {
public:
    Packet();
    virtual BOOL Execute(Side*) = 0;
    inline BOOL set_message(google::protobuf::Message* message){
        return (message_ = message);
    };
    virtual ~Packet();
    inline INT packet_type(){return packet_type_;}
//    UINT size(){return sizeof(PacketHead) + (INT)message_->ByteSize();}
//    inline PacketHead& packet_head(){return packet_head_;}
    inline google::protobuf::Message* message(){return message_;}
protected:
    INT packet_type_;
    google::protobuf::Message* message_;
};

#endif /* PACKET_H_ */
