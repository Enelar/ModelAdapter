#pragma once

namespace original_source_code
{
  struct CZadvW
  {
    double Vent;
    double VentZ;
  };
}

#include "../objects.h"

namespace objects
{
  typedef ::mapper<original_source_code::CZadvW> gate_valve;
}

template<>
void objects::gate_valve::UpdateRouteTable(objects::gate_valve &m);