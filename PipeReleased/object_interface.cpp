#include "object_interface.h"

object_interface::object_interface(word _id, OBJECT_TYPES _type)
: id(_id), type(_type)
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

void object_interface::SetParam(param p)
{
  todo("Set param bind to model");
}

serialised_param object_interface::GetSimpleParam() const
{
  return GetParam(0);
}
serialised_param object_interface::GetParam(word param) const
{
  todo("Get param bind to model");
}
