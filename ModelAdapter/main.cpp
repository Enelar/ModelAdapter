#include "../PipeReleased/Pipe.h"
#include "../PipeReleased/objects.h"
#include <iostream>

void main()
{
  pipe p;
  object_interface obj = p.Get(VALVE, "PV10-229");
  std::cout << obj.GetID() << std::endl;

  auto info = obj.GetInfo();
  auto value = obj.GetParam<double>(0);
  value += 10; // like unity
  obj.SetParam<double>(0, value);
}