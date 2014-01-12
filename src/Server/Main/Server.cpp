/*
 * Copyright (C) 2013-2014 Project_H. All rights reserved.
 *
 * Language: UTF-8
 * Maximum line width: 80 chars
 * Tab width: 4 spaces
 *
 *  File name: Server.cpp
 *  Created on: 2014-1-1
 *  Author: tmdjojo
 *  Description:
 */

#include "Server.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../Common/Type.h"
#include "../Common/Packet.h"
#include "../Python/PythonScript.h"
#include "../Python/Python2CWorld.h"

Server::Server() :
    is_burn_(FALSE)
{

}

Server::~Server() {

}

BOOL Server::Init(){
    g_python_script = new PythonScript();
    if(NULL == g_python_script)
        return FALSE;
    if(!g_python_script->Init()){
        SAFE_DELETE(g_python_script);
        return FALSE;
    }

    return TRUE;
}

BOOL Server::Loop(){
    is_burn_ = TRUE;

    while(is_burn_){

        sleep(100);
    }
    return TRUE;
}
BOOL Server::Exit(){

    return TRUE;
}
int sayHello(){
    printf("python call c ...\n");
    return 0;
}
#include <boost/python.hpp>
BOOST_PYTHON_MODULE(hello){
    using namespace boost::python;

    def("sayHello",sayHello);
}
INT main(INT argc, CHAR* argv[]){
    printf("hello server!\n");

    if(argc>1){
        for( int i=1; i<argc; i++ ){
            if( strcmp(argv[i],"") !=0 ){
                printf("argv[%d]:[%s]\n",i,argv[i]);
            }
        }
    }
    static pid_t pid = fork();
    if(pid > 0){
        printf("Server start pid %d ...\n",pid);
        return 0;
    }

    Server* server = new Server();
    if(NULL == server){
        printf("new server fail!\n");
        return -1;
    }

    if( !server->Init() ){
        printf("server init fail!\n");
        return -1;
    }
    {
        PyThreadStateAutoLock lock;
        inithello();
        initPython2CWorld();
    }

//    g_python_script->CallFunction("print 'hello python'");
    g_python_script->CallFunction("ftp","sayhi","c call python 1234");


//    if( !server->Loop() ){
//        printf("server loop fail!\n");
//        return -1;
//    }

    if( !server->Exit() ){
        printf("server exit fail!\n");
        return -1;
    }
    SAFE_DELETE(server);

    printf("bye server!\n");
    return 0;
}
