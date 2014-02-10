/*
 * ClientManage.cpp
 *
 *  Created on: 2014年1月24日
 *      Author: tmdjojo
 */

#include "ClientManage.h"
#include <stdio.h>
#include "./ClientPool.h"
#include <boost/thread.hpp>

ClientManage* g_client_manage = NULL;

ClientManage::ClientManage()
//        thread(run)
{
    // TODO Auto-generated constructor stub
    is_burn_ = FALSE;
}

ClientManage::~ClientManage() {
    // TODO Auto-generated destructor stub
}

void ClientManage::operator()(){
    while(is_burn_){
        OutputStream();
        Execute();
        InputStream();
        boost::xtime time;
        time.sec = 0;
        time.nsec = 10;
        boost::thread::sleep(time);
    }
}

VOID ClientManage::InputStream(){
    for(UINT index = 0;index < MAX_CLIENT_SIZE;++index){
        Client* client = g_client_pool->GetClient(index);
        if(NULL == client)
            continue;
        client->Input();
    }
}

VOID ClientManage::OutputStream(){
    for(UINT index = 0;index < MAX_CLIENT_SIZE;++index){
        Client* client = g_client_pool->GetClient(index);
        if(NULL == client)
            continue;
        client->Output();
    }
}

VOID ClientManage::Execute(){
    for(UINT index = 0;index < MAX_CLIENT_SIZE;++index){
        Client* client = g_client_pool->GetClient(index);
        if(NULL == client)
            continue;

    }
}
