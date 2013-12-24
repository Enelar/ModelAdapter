#include "../PipeExport/server_object_container.h"
#include "server_serialisator.h"
#include "mapper\mapper.h"

#include "../ASN1/ASN1/asn1.h"

#include "../ASN1/ASN1/internal_header.h"

using namespace asn1;
REFACTOR
struct dummy_double : asn1::entity
{
  double t;
  dummy_double(double _t)
  : entity(asn1::inditifier(inditifier::APPLICATION, false, VALUE_TYPE::FLOAT)),  t(_t)
  {

  }

  operator std::string() const
  {
    string ret;

    ConCat(ret, type);
    ConCat(ret, EncodeLength());

    const entity::byte *_content = reinterpret_cast<const entity::byte *>(&t);
    for (word i = 0; i < sizeof(t); i++)
      ret += _content[i];
    return ret;
  }
  
  int Length() const
  {
    return sizeof(double);
  }
  
  LENGTH_TYPE LengthType() const
  {
    return LENGTH_TYPE::DEFINITE;
  }
};

#include "exported\scheme_data.h"

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