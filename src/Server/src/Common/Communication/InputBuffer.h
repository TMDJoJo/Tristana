/*
 * InputBuffer.h
 *
 *  Created on: 2014年1月23日
 *      Author: tmdjojo
 */

#ifndef INPUTBUFFER_H_
#define INPUTBUFFER_H_

#define MAX_INPUT_BUFFER_LEN    512*1024    ////0.5M
#include <google/protobuf/message.h>
#include "../Type.h"
#include "../Packet/Packet.h"
#include "./Socket/ActiveSocket.h"

class InputBuffer {
public:
    InputBuffer();
    virtual ~InputBuffer();
    Packet* DecodeMessage();
    INT ReadSocket(CActiveSocket*);

//    inline UINT data_lengtn(){return data_length_;}
private:
    INT Read(CHAR* buf,UINT len);
    INT Write(const CHAR* buf,UINT len);
private:
    char data_[MAX_INPUT_BUFFER_LEN];

    UINT data_head_;
    UINT data_tail_;
    UINT data_length_;
};

#endif /* INPUTBUFFER_H_ */
