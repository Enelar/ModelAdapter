#include "stdafx.h"

#include <vector>
#include "param.h"

template<typename T>
bool server_serializator(const server_object_container<typename T::mapped> &, vector<param> &)
{
  IMPLEMENTATION_REQUIRED
}

#include "objects.h"

template<typename T>
bool basic_server_serializator(const server_object_container<typename T::mapped> &, vector<param> &);

template<>
bool server_serializator<objects::valve>(const server_object_container<objects::valve::mapped> &server_obj, vector<param> &ret);
template<>
bool server_serializator<objects::gate_valve>(const server_object_container<objects::gate_valve::mapped> &server_obj, vector<param> &ret);