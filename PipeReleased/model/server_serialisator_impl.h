#pragma once
#include "server_serialisator.h"

#define _SERVER_SERIALISATOR_DECLARE(_type_)     \
  template<>                                      \
    bool server_serializator<_type_>(const server_object_container<_type_::mapped> &(server_obj), vector<param> &ret)

#define _SERVER_SERIALISATOR_IMPL(_type_)  \
  _SERVER_SERIALISATOR_DECLARE(_type_)      \
  {                                          \
    return basic_server_serializator<_type_>(server_obj, ret); \
  }

#ifdef _SERVER_SERIALISATOR_SHROODINGER
#define _SERVER_SERIALISATOR_SUPERPOSITION(type) _SERVER_SERIALISATOR_IMPL(type)
#else
#define _SERVER_SERIALISATOR_SUPERPOSITION(type) _SERVER_SERIALISATOR_DECLARE(type)
#endif

_SERVER_SERIALISATOR_SUPERPOSITION(objects::valve);
_SERVER_SERIALISATOR_SUPERPOSITION(objects::gate_valve);