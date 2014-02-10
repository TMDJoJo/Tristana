/*
 * Side.h
 *
 *  Created on: 2014.1.23
 *      Author: tmdjojo
 */

#ifndef SIDE_H_
#define SIDE_H_

#include "./Socket/ActiveSocket.h"
#include "../Packet/Packet.h"
#include "./InputBuffer.h"
#include "./OutputBuffer.h"

class Side {
public:
    Side();
    virtual ~Side();
    INT SendPacket(Packet*);

    virtual INT Execute() = 0;
    BOOL Input();
    BOOL Output();
protected:
    Packet* ReceivePacket();
private:
    CActiveSocket* socket_;
    InputBuffer input_buffer_;
    OutputBuffer output_buffer_;
};

#endif /* SIDE_H_ */
