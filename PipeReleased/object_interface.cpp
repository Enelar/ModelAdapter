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