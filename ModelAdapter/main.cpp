#include "../PipeReleased/Pipe.h"
#include "../PipeReleased/mapper.h"
#include <iostream>


template<>
void mapper<pipe>::UpdateRouteTable(mapper &)
{
  todo(pipe support);
}

void main()
{
  pipe p;
  object_interface obj = p.Get(VALVE, "PV10-229");
  std::cout << obj.GetID() << std::endl;

  mapper<pipe> a;
  a.Platform(&p);
  a.Get<int>("name");
//  exported_pipe t("test");
}