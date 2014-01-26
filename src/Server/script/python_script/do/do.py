#! /usr/bin/env python2.7
# -*- coding: utf8 -*-

import sys
import time
import cpp_template

def sayhi(name):
    print '    >>>',name
    print cpp_template.SayHello()
    print cpp_template.SayHelloS('hello c++')
    print cpp_template.SayHelloSI('hello c++',101)

    return name
    #return 110

if __name__=='__main__':
    sayhi("main")
