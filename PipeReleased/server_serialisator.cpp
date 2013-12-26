#include "../PipeExport/server_object_container.h"
#include "server_serialisator.h"
#include "mapper\mapper.h"

#include "exported\scheme_data.h"

#include "DummyDouble.h"

template<typename T>
bool basic_server_serializator(const server_object_container<typename T::mapped> &server_obj, vector<param> &ret)
{
  const T m;
  const ub *mem = server_obj.Memory() + sizeof(original_source_code::CShBase) + sizeof(original_source_code::CFlags);
  m.Platform(reinterpret_cast<typename const T::mapped *>(mem));

  auto SerializeParam = [](double val) -> string
  {
    asn1::stream str;
    dummy_double d(val);
    str << d;    
    return str;
  };

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

template<>
bool server_serializator<objects::valve>(const server_object_container<objects::valve::mapped> &server_obj, vector<param> &ret)
{
  return basic_server_serializator<objects::valve>(server_obj, ret);
}

template<>
bool server_serializator<objects::gate_valve>(const server_object_container<objects::gate_valve::mapped> &server_obj, vector<param> &ret)
{
  return basic_server_serializator<objects::gate_valve>(server_obj, ret);
}