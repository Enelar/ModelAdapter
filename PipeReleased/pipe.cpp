#include "Pipe.h"
#include "../PipeExport/exported_pipe.h"

pipe::pipe()
{
  ep = new exported_pipe("aa");
}

pipe::~pipe()
{
  delete ep;
}

object_interface pipe::Get(OBJECT_TYPES type, std::string name)
{
  word id = GetID(type, name);
  return Get(id);
}

object_interface pipe::Get(word _id)
{
  throw_assert(_id != 0);
  object_interface obj;
  obj.id = _id;
  return obj;
}

word pipe::GetID(OBJECT_TYPES type, std::string name)
{
  return ep->GetPipeElement(type, name.c_str());
}