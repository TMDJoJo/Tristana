/*
 * OutputBuffer.cpp
 *
 *  Created on: 2014.1.23
 *      Author: tmdjojo
 */

#include "OutputBuffer.h"
#include <string.h>

#define SOCKET_MAX_WRITE_LEN    8*1024

OutputBuffer::OutputBuffer() {
    // TODO Auto-generated constructor stub
    data_head_ = 0;
    data_tail_ = 0;
    data_length_ = 0;
}

OutputBuffer::~OutputBuffer() {
    // TODO Auto-generated destructor stub
}

INT OutputBuffer::WriteSocket(CActiveSocket* socket){
    if(NULL == socket
            ||!socket->IsSocketValid()){
        ////socket error
        return 1;
    }
    INT write_len = SOCKET_MAX_WRITE_LEN;
    SOCKET_MAX_WRITE_LEN > data_length_ ? write_len = data_length_ : 0;

    INT remaind_len = write_len - 1 - data_head_;
    INT send_len = 0;
    if(remaind_len < write_len){
        send_len = socket->Send((UCHAR*)&data_[data_head_],remaind_len);
        if(send_len <= 0
                ||send_len > remaind_len){
            ////disconnect
            return -1;
        }
    }
    else{
        send_len = socket->Send((UCHAR*)&data_[data_head_],write_len);
        if(send_len <= 0
                ||send_len > write_len){
            ////disconnect
            return -1;
        }
    }
    data_length_ -= send_len;
    data_head_ = (data_head_ + send_len)%MAX_OUTPUT_BUFFER_LEN;
    return 0;
}

INT OutputBuffer::EncodeMessage(Packet* packet){
    if(NULL == packet)
        return 0;
    google::protobuf::Message* message = packet->message();
    PacketHead head;
    if(NULL == message){
        ////empty message case
        UINT len = sizeof(PacketHead);
        if(MAX_OUTPUT_BUFFER_LEN - data_length_ < len){
            ////no much buffer space
            return -1;
        }
        head.packet_type_ = packet->packet_type();
        head.data_length_ = 0;
        ////TODO set head.crc32_
        return Write((CHAR *)&head,len);
    }
    else{
        ////normal case
        head.packet_type_ = packet->packet_type();
        head.data_length_ = message->ByteSize();
        ////TODO set head.crc32_
        UINT len = sizeof(PacketHead) + head.data_length_ + sizeof(INT);
        if(MAX_OUTPUT_BUFFER_LEN - data_length_ < len){
            ////no much buffer space
            return -1;
        }
        INT re = Write((CHAR *)&head,len);
        if(re != 0){
            ////write head error
            return re;
        }
        CHAR* message_data = new CHAR[head.data_length_];
        if(NULL == message_data){
            ////no much space for message data
            return 1;
        }
        if(!message->SerializeToArray(message_data,head.data_length_)){
            ////message serialize error
            SAFE_DELETE_ARRAY(message_data);
            return 2;
        }
        re = Write(message_data,head.data_length_);
        if(0 != re){
            return re;
        }
        ////TODO set crc32
        INT message_data_crc32 = 0;
        re = Write((CHAR*)&message_data_crc32,sizeof(INT));
        if(0 != re){
            return re;
        }
        SAFE_DELETE_ARRAY(message_data);

        data_tail_ = (data_tail_ + len)%MAX_OUTPUT_BUFFER_LEN;
        data_length_ += len;
        return 0;
    }
}

INT OutputBuffer::Write(const CHAR* buf,UINT len){
    if(len > MAX_OUTPUT_BUFFER_LEN - data_length_){
        ////缓冲区空间不足
        return -1;
    }
    UINT remaind_len = MAX_OUTPUT_BUFFER_LEN - 1 - data_tail_;
    if( remaind_len < len ){
        memcpy(&data_[data_tail_],buf,remaind_len);
        memcpy(&data_[0],buf+remaind_len,len - remaind_len);
//        data_tail_ = len - remaind_len;
//        data_length_ += len;
    }
    else{
        memcpy(&data_[data_tail_],buf,len);
//        data_tail_ += len;
//        data_length_ += len;
    }
    return 0;
}
