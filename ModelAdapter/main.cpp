#include "../PipeReleased/Pipe.h"
#include "../PipeReleased/objects.h"
#include <iostream>

void main()
{
  throw_assert(object_id<objects::valve>::tid != NOTANOBJECT);
  auto p = pipe::Make();
  object_interface obj = p->Get(VALVE, "PV10-229");
  std::cout << obj.GetID() << std::endl;

  auto info = obj.GetInfo();
  auto value = obj.GetParam(0);
  //value += 10; // like unity
  //obj.SetParam(0, value);
  p->Shutdown();
}