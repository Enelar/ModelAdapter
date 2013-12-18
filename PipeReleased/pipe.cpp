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
  return ObjectPostChange(Get(type, id));
}

object_interface pipe::Get(const OBJECT_TYPES type, const word id)
{
  throw_assert(id != 0);
  throw_assert(type != NOTANOBJECT);
  object_interface obj(id, type);
  return obj;
}

object_interface pipe::Get(word _id)
{
  todo(Enumerate over types and find type);
}

object_interface pipe::Get(const std::string &name)
{
  word res = 0;
  
  for each(OBJECT_TYPES type in SupportedTypes())
  {
    auto t = Get(type, name);
    if (t.GetID())
      return t;
  }
  throw_message("Object not found");
}

word pipe::GetID(const OBJECT_TYPES type, const std::string &name)
{
  return ep->GetID(type, name.c_str());
}

vector<param> pipe::GetRaw(const object_interface &obj)
{
  implementation_required("Get full object information from model. Exported pipe needed");
}

void pipe::SetRaw(const object_interface &obj, vector<param> data)
{
  auto info = obj.GetInfo();
  for each (auto p in data)
  {
    throw_sassert(!info.params[1].readonly, "Write protection on this parameter");
    double t, t2;
    string server_mapped_name;
    ep->SetServerTile(obj.GetID(), server_mapped_name.c_str(), original_source_code::enumValueDbl, &t, &t2);
  }
}
