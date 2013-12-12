namespace original_source_code
{
  struct CSensorW
  {
    // Сохраняемые данные
    double SensValue;
    double PhysValue;
    double ShowValue;
    double To_kg;
    double To_m3;
    double A, B;
    double ErrValue;
    int Mes;
    int O;
  };
}

#include "../objects.h"

namespace objects
{
  typedef ::mapper<original_source_code::CSensorW> sensor;
}

template<>
void objects::sensor::UpdateRouteTable(objects::sensor &m);