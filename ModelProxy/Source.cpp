#include "Header.h"

model::model()
{
  p = NEW MEMLEAK pipe::store_type(pipe::Make());
}

model::~model()
{
  delete p;
}


object model::Get(const char *str)
{
  auto obj = NEW MEMLEAK object_interface(Pipe()->Get(str));
  return{ obj };
}

object model::Get(int id)
{
  auto obj = NEW MEMLEAK object_interface(Pipe()->Get((word)id));
  return{ obj };
}

int model::GetID(const char *str)
{
  if (str == nullptr)
    return 0;
  auto obj = Pipe()->Get(str);
  return obj.GetID();
}

pipe::store_type model::Pipe() const
{
  return *p;
}