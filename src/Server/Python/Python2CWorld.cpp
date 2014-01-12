/*
 * Python2CWorld.cpp
 *
 *  Created on: 2014年1月7日
 *      Author: tmdjojo
 */

#include "Python2CWorld.h"
#include <boost/python.hpp>

Python2CWorld::Python2CWorld() {
    // TODO Auto-generated constructor stub

}

Python2CWorld::~Python2CWorld() {
    // TODO Auto-generated destructor stub
}

Python2CWorld* WorldInit(){
    return new Python2CWorld();
}

BOOST_PYTHON_MODULE(Python2CWorld)
{
    using namespace boost::python;
    def("WorldInit",WorldInit,
            return_value_policy<reference_existing_object>());
    class_ <Python2CWorld>("Python2CWorld",init<>())
            .def("Hello", &Python2CWorld::Hello)
            ;
//      register_ptr_to_python <world_ptr>();
}
