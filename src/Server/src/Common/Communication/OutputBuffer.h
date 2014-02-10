/*
 * OutputBuffer.h
 *
 *  Created on: 2014.1.23
 *      Author: tmdjojo
 */

#ifndef OUTPUTBUFFER_H_
#define OUTPUTBUFFER_H_
#include "../Type.h"
#include "../Packet/Packet.h"
#include "./Socket/ActiveSocket.h"

#define MAX_OUTPUT_BUFFER_LEN 1024*1024    ////1M

class OutputBuffer {
public:
    OutputBuffer();
    virtual ~OutputBuffer();
    INT WriteSocket(CActiveSocket*);
    INT EncodeMessage(Packet*);
//    inline UINT remain_length(){return MAX_OUTPUT_BUFFER_LEN - data_length_;}
private:
    INT Write(const CHAR* buf,UINT len);
private:
    char data_[MAX_OUTPUT_BUFFER_LEN];

    UINT data_head_;
    UINT data_tail_;
    UINT data_length_;
};

#endif /* OUTPUTBUFFER_H_ */
