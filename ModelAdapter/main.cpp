#include "../PipeReleased/Pipe.h"
#include <iostream>

void main()
{
  pipe p;
  object_interface obj = p.Get(VALVE, "PV10-229");
  std::cout << obj.GetID() << std::endl;
//  exported_pipe t("test");
}