/*
 * PythonScript.cpp
 *
 *  Created on: 2014年1月7日
 *      Author: tmdjojo
 */

#include "PythonScript.h"

PythonScript* g_python_script = NULL;
PythonScript::PythonScript(){

}

PythonScript::~PythonScript() {

    if(0 != Py_IsInitialized){
        Py_Finalize();
    }
}

BOOL PythonScript::Init(){
    Py_Initialize();
    if(0 == Py_IsInitialized()){
        printf("Python initialize fail!\n");
        return FALSE;
    }
    else{
        printf("Python initialize success!\n");
    }
    ////初始化线程支持
    PyEval_InitThreads();
    PyEval_ReleaseThread(PyThreadState_Get());

    INT result = CallFunction("import sys");
    if(-1 == result)
        return FALSE;

    result = CallFunction("sys.path.append('../Script')");
    if(-1 == result)
        return FALSE;

    return TRUE;
}

INT PythonScript::CallFunction(const char* script){
    if(NULL == script)
            return -1;
    INT result = -1;
    PyThreadStateAutoLock lock;
    result = PyRun_SimpleString(script);

    return result;
}

INT PythonScript::CallFunction(const char* module_name,
        const char* function_name,const char* param){
    if(NULL == module_name
            ||NULL == function_name
            )
        return -1;
    INT re = -1;
    PyObject* module = NULL,
            * dictionary = NULL,
            * function = NULL,
            * result = NULL;

    do{
        PyThreadStateAutoLock lock;
        ////导入模块
        module = PyImport_ImportModule(module_name);
        if (!module) {
            printf("Can't open python file[%s]!\n",module_name);
            re = -1;
            break;
        }
        ////模块的字典列表
        dictionary = PyModule_GetDict(module);
        if (!dictionary) {
            printf("Can't find dictionary.\n");
            re = -1;
            break;
        }
        ////获得函数
        function = PyDict_GetItemString(dictionary,function_name);
        if(!function
                ||!PyCallable_Check(function)){
            printf("Can't find function[%s].\n",function_name);
            re = -1;
            break;
        }

        ////函数调用
        result = PyObject_CallFunction(function,"s",param);
        if(!result){
            printf("Call function[%s] fail.\n",function_name);
            re = -1;
            break;
        }
        break;
    }while(1);

    if(result)
        Py_DECREF(result);
    if(function)
        Py_DECREF(function);
    if(dictionary)
        Py_DECREF(dictionary);
    if(module)
        Py_DECREF(module);

    return re;
}

