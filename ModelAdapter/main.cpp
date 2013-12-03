#include "../PipeReleased/Pipe.h"
#include "../PipeReleased/mapper.h"
#include <iostream>

struct my_struct
{
  double A, B, SLGDLKJGHSLKGJFG;
};

template<>
void mapper<my_struct>::UpdateRouteTable(mapper &m)
{
  m.Register("A", &my_struct::A);
  m.Register("B", &my_struct::B);
  m.Register("Hard", &my_struct::SLGDLKJGHSLKGJFG);
  m.Register("Synonim", &my_struct::SLGDLKJGHSLKGJFG);
}

void main()
{
  pipe p;
  object_interface obj = p.Get(VALVE, "PV10-229");
  std::cout << obj.GetID() << std::endl;

  my_struct origin;
  mapper<my_struct> a;
  a.Platform(&origin);
  a.Set<double>("Hard", 5);
}