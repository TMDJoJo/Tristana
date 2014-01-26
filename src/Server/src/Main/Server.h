/*
 * Copyright (C) 2013-2014 Project_H. All rights reserved.
 *
 * Language: UTF-8
 * Maximum line width: 80 chars
 * Tab width: 4 spaces
 *
 *  File name: Server.h
 *  Created on: 2014-1-1
 *  Author: tmdjojo
 *  Description:
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "../Common/Type.h"

class Server {
public:
    Server();
    virtual ~Server();

    BOOL Init();    ////initialize server
    BOOL Loop();    ////run the daemon thread
    BOOL Exit();    ////exit process and free memory

private:
    BOOL is_burn_;     ////

};
#endif /* SERVER_H_ */
