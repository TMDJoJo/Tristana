/*
 * OutputBuffer.h
 *
 *  Created on: 2014年1月23日
 *      Author: tmdjojo
 */

#ifndef OUTPUTBUFFER_H_
#define OUTPUTBUFFER_H_
#include "../Type.h"
#include "../Packet/Packet.h"

#define MAX_OUTPUT_BUFFER_LEN 8*1024

class OutputBuffer {
public:
    OutputBuffer();
    virtual ~OutputBuffer();
//    INT Send();
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
