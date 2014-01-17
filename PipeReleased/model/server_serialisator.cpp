#define _SERVER_SERIALISATOR_SHROODINGER

#include "../../PipeExport/server_object_container.h"
#include "server_serialisator.h"
#include "mapper\mapper.h"

#include "objects\exported\scheme_data.h"

#include "../DummyDouble.h"

namespace
{
  template<typename T>
  auto SerializeParam(const T &)->string
  {
    IMPLEMENTATION_REQUIRED
  }

  template<>
  auto SerializeParam(const double &val)->string
  {
    asn1::stream str;
    dummy_double d(val);
    str << d;
    return str;
  }
}

template<typename T>
bool basic_server_serializator(const server_object_container<typename T::mapped> &server_obj, vector<param> &ret)
{
  const T m;
  const ub *mem = server_obj.Memory() + sizeof(original_source_code::CShBase) + sizeof(original_source_code::CFlags);
  m.Platform(reinterpret_cast<typename const T::mapped *>(mem));

  int id = 0;
  param p;
  p.raw.t = VALUE_TYPE::FLOAT;
  for (auto t : m.RouteTable().ShowMap())
  {
    throw_sassert(t.second.type == VALUE_TYPE::FLOAT, "Other types didnt implemented yet");
    auto val = m.Get<double>(t.first);
    p.id = id++;
    p.raw.asn1_encoded_string = SerializeParam(val);
    ret.push_back(p);
  }
  return true;
}