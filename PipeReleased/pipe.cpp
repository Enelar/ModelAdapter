#include "Pipe.h"
#include "../PipeExport/exported_pipe.h"

pipe::pipe(const std::string &named_pipe)
{
  ep = new exported_pipe(named_pipe.c_str());
}

pipe::~pipe()
{
  delete ep;
}

object_interface pipe::Get(const OBJECT_TYPES type, const std::string &name)
{
  word id = GetID(type, name);
  return Get(id);
}

object_interface pipe::Get(word _id)
{
  throw_assert(_id != 0);
  object_interface obj(_id);
  return obj;
}

object_interface pipe::Get(const std::string &name)
{
  word res = 0;
  
  for each(OBJECT_TYPES type in supported_types)
    if (res = GetID(type, name))
      return object_interface(res);
  throw_message("Object not found");
}

word pipe::GetID(const OBJECT_TYPES type, const std::string &name)
{
  return ep->GetID(type, name.c_str());
}