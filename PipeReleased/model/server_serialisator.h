#pragma once

#include "../stdafx.h"

#include <vector>
#include "../interface/param.h"

template<typename T>
bool server_serializator(const server_object_container<typename T::mapped> &, vector<param> &)
{
  IMPLEMENTATION_REQUIRED
}

#include "objects\objects.h"

template<typename T>
bool basic_server_serializator(const server_object_container<typename T::mapped> &, vector<param> &);

#include "server_serialisator_impl.h"