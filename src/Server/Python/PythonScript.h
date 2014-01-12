/*
 * PythonScript.h
 *
 *  Created on: 2014年1月7日
 *      Author: tmdjojo
 */

#ifndef PYTHONSCRIPT_H_
#define PYTHONSCRIPT_H_

#include <python2.7/Python.h>
#include "../Common/Type.h"

class PyThreadStateAutoLock {
public:
    PyThreadStateAutoLock(){
        state_ = PyGILState_Ensure();
    }

    ~PyThreadStateAutoLock(void){
        PyGILState_Release(state_);
    }
private:
    PyGILState_STATE state_;
};

class PythonScript {

public:
    PythonScript();
    virtual ~PythonScript();
    BOOL Init();

    INT CallFunction(const char* );
    INT CallFunction(const char* module_name,
            const char* function_name,const char* param);
private:

};

extern PythonScript* g_python_script;

#endif /* PYTHONSCRIPT_H_ */
