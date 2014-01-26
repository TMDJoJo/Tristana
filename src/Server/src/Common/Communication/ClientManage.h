/*
 * ClientManage.h
 *
 *  Created on: 2014年1月24日
 *      Author: tmdjojo
 */

#ifndef CLIENTMANAGE_H_
#define CLIENTMANAGE_H_

#include <stdio.h>
#include "../Type.h"

class ClientManage{
public:
    ClientManage();
    virtual ~ClientManage();
    VOID InputStream();
    VOID OutputStream();
    VOID Execute();
    void operator()();
private:
    BOOL is_burn_;
};
extern ClientManage* g_client_manage;
#endif /* CLIENTMANAGE_H_ */
