/*
 * Python2CWorld.h
 *
 *  Created on: 2014年1月7日
 *      Author: tmdjojo
 */

#ifndef PYTHON2CWORLD_H_
#define PYTHON2CWORLD_H_
#include <stdio.h>

extern "C" void initPython2CWorld();

class Python2CWorld {
public:
    Python2CWorld();
    virtual ~Python2CWorld();

    void Hello(){ printf("hello c ++\n"); }
};

#endif /* PYTHON2CWORLD_H_ */
