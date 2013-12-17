#include "object_interface.h"

object_interface::object_interface(word _id)
: id(_id)
{

}

word object_interface::GetID() const
{
  return id;
}

info object_interface::GetInfo() const
{
  REFACTOR // I know this is wrong, and i should return direct reference to DB. But Boss want results NOW.
  return object_info;
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
