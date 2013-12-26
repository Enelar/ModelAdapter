#include "../PipeReleased/Pipe.h"
#include "../PipeReleased/objects.h"
#include <iostream>


void f()
{
  throw_assert(object_id<objects::valve>::tid != NOTANOBJECT);
  auto p = pipe::Make();
  object_interface obj = p->Get(VALVE, "Z-15");
  std::cout << obj.GetID() << std::endl;

  auto info = obj.GetInfo();
  auto value = obj.GetParam(0);
  //value += 10; // like unity
  //obj.SetParam(0, value);
  p->Shutdown();
}

#include "../ModelProxy/Header.h"

void f1()
{
  int model = Construct();
  int handle = Get(model, "Z-15");
  while (1)
  {
    double param = GetDouble(handle, 0);
    std::cout << param << std::endl;
  }
  DestructObject(handle);
  Destruct(model);
}

void main()
{
  //f();
  f1();
}