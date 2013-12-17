#include "pipe.h"
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
  auto ObjectPostChange = [type](object_interface &obj)
  {
    auto record = ObjectsInfo().find(type);
    obj.object_info = record->second;
    return obj;
  };

  word id = GetID(type, name);
  return ObjectPostChange(Get(id));
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
  
  for each(OBJECT_TYPES type in SupportedTypes())
    return Get(type, name);
  throw_message("Object not found");
}

word pipe::GetID(const OBJECT_TYPES type, const std::string &name)
{
  return ep->GetID(type, name.c_str());
}