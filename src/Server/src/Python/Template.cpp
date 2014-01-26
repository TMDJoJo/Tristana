/*
 * Template.cpp
 *
 *  Created on: 2014年1月13日
 *      Author: tmdjojo
 */

#include "Template.h"

namespace Python{

PyObject* SayHello(PyObject *self, PyObject *args){
    printf("python call c ...\n");
    return Py_BuildValue("i",0);
}

////接口函数实现
PyObject* SayHelloS(PyObject *self, PyObject *args){

    const char* string;
    ////这句是把python的变量args转换成c的变量command
    if(!PyArg_ParseTuple(args, "s", &string))
        return Py_BuildValue("i", -1);
    printf("python call c %s ...\n",string);
    return Py_BuildValue("i",0);
}

PyObject* SayHelloSI(PyObject *self, PyObject *args){
    const char* string;
    int d;
    if(!PyArg_ParseTuple(args, "si", &string,&d))
        return Py_BuildValue("i", -1);
    printf("python call c %s %d ...\n",string,d);
    return Py_BuildValue("i",0);
}

///导出方法列表
static PyMethodDef cpp_methods_export[] = {
    { "SayHello", SayHello, METH_VARARGS, "print a string." },
    { "SayHelloS", SayHelloS, METH_VARARGS, "print a string." },
    { "SayHelloSI", SayHelloSI, METH_VARARGS, "print a string." },
    { NULL, NULL, 0, NULL }
};

////模块初始化方法
PyMODINIT_FUNC initTemplate(void){
    ////初始模块，把MyCppMethods初始到MyCppModule中
    PyObject *m = Py_InitModule("cpp_template", cpp_methods_export);
    if (m == NULL)
        return;
}

}
