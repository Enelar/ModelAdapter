#include "object_interface.h"

object_interface::object_interface()
{

}

word object_interface::GetID() const
{
  return id;
}

info object_interface::GetInfo() const
{
  return object_info;
}