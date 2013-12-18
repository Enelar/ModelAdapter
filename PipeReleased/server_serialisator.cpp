#include "../PipeExport/server_object_container.h"
#include "server_serialisator.h"
#include "mapper\mapper.h"

template<typename T>
bool basic_server_serializator(const server_object_container<typename T::mapped> server_obj, vector<param> &ret)
{
  const objects::valve m;
  m.Platform(&*server_obj);

  auto SerializeParam = [](double val)
  {
    todo("Serialize with ASN1");
    return "";
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
bool server_serializator<objects::valve>(const server_object_container<objects::valve::mapped> server_obj, vector<param> &ret)
{
  return basic_server_serializator<objects::valve>(server_obj, ret);
}