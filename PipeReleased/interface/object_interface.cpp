#include "object_interface.h"

object_interface::object_interface( const pipe &_pipe, word _id, OBJECT_TYPES _type)
: id(_id), type(_type), p(_pipe.Ref())
{

}

word object_interface::GetID() const
{
  return id;
}

info object_interface::GetInfo() const
{
  return ObjectsInfo().find(type)->second;
}

void object_interface::SetSimpleParam(serialised_param p)
{
  SetParam(0, p);
}

void object_interface::SetParam(word param, serialised_param value)
{
  SetParam({ param, value });
}

void object_interface::SetParam(param par)
{
  p->SetRaw(*this, { par });
}

serialised_param object_interface::GetSimpleParam() const
{
  return GetParam(0);
}
serialised_param object_interface::GetParam(word param) const
{
  auto info = ObjectsInfo().find(type)->second;
  throw_sassert(info.params.size() > param, "Subscript out of range");
  auto params = p->GetRaw(*this);
  throw_sassert(info.params.size() == params.size(), "Object information about parameters desync");
  throw_sassert(params[param].raw.t == info.params[param].type, "Object information about parameter types desync");
  return params[param].raw;
}
