/*
 * InputBuffer.cpp
 *
 *  Created on: 2014.1.23
 *      Author: tmdjojo
 */

//INT NAMELEN;
//INT DATALEN;
//INT CRC;
//CHAR NAME[NAMELEN];
//CHAR DATA[DATALEN];
//INT CRC;
//
//1.read 12B len info
//2.check CRC
//3.read name and data and CRC
//4.check CRC
//

#include "InputBuffer.h"
#include "../Packet/PacketFactory.h"
#define SOCKET_MAX_READ_LEN    8*1024


InputBuffer::InputBuffer() {
    // TODO Auto-generated constructor stub
    data_head_ = 0;
    data_tail_ = 0;
    data_length_ = 0;
}

InputBuffer::~InputBuffer() {
    // TODO Auto-generated destructor stub
}

Packet* InputBuffer::DecodeMessage(){
    if(data_length_ < sizeof(PacketHead)){
        return NULL;
    }
    PacketHead head;
    if( 0 != Read((CHAR*)&head,sizeof(PacketHead)) ){
        ////read packet head error
        return NULL;
    }
    ////TODO crc32 check head
    if(data_length_ < sizeof(PacketHead) + head.data_length_ + sizeof(INT)){
        ////no full packet
        return NULL;
    }
    CHAR* message_data = new CHAR[head.data_length_];
    if(NULL == message_data)
        return NULL;
    if(0 != Read(message_data,sizeof(head.data_length_))){
        ////read message error
        return NULL;
    }
    INT data_crc32;
    if(0 != Read((CHAR*)&data_crc32,sizeof(INT))){
            ////read crc32 error
            return NULL;
    }
    data_head_ = (data_head_ + sizeof(PacketHead) +
            head.data_length_ + sizeof(INT))%MAX_INPUT_BUFFER_LEN;
    ////TODO crc32 check message data
    Packet* packet = PacketFactory::Create(head,message_data);
    SAFE_DELETE_ARRAY(message_data);

    return packet;
}

INT InputBuffer::ReadSocket(CActiveSocket* socket){
    if(NULL == socket
            ||!socket->IsSocketValid()){
        ////socket error
        return 1;
    }
    if(SOCKET_MAX_READ_LEN > MAX_INPUT_BUFFER_LEN - data_length_){
        ////no much buffer
        return 0;
    }
    int len = socket->Receive(SOCKET_MAX_READ_LEN);
    if(len <= 0){
        return 1;
    }
    return Write((CHAR*)socket->GetData(),len);
}

INT InputBuffer::Write(const CHAR* buf,UINT len){
    if(len > MAX_INPUT_BUFFER_LEN - data_length_){
        ////no much buffer
        return -1;
    }
    UINT remaind_len = MAX_INPUT_BUFFER_LEN - 1 - data_tail_;
    if( remaind_len < len ){
        memcpy(&data_[data_tail_],buf,remaind_len);
        memcpy(&data_[0],buf + remaind_len,len - remaind_len);
        data_tail_ = len - remaind_len;
        data_length_ += len;
    }
    else{
        memcpy(&data_[data_tail_],buf,len);
        data_tail_ += len;
        data_length_ += len;
    }

    return 0;
}

INT InputBuffer::Read(CHAR* buf,UINT len){
    if(len > data_length_)
        return -1;
    UINT remaind_len = MAX_INPUT_BUFFER_LEN - 1 - data_head_;
    if(remaind_len < len){
        memcpy(buf,&data_[data_head_],remaind_len);
        memcpy(buf + remaind_len,&data_[0],len - remaind_len);
    }
    else{
        memcpy(buf,&data_[data_head_],len);
    }
    return 0;
}
