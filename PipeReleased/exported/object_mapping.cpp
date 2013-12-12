#include "../objects.h"

template<>
void objects::air_condenser::UpdateRouteTable(objects::air_condenser &m)
{
  ////m.Register("display", &mapped::Type_Flags); CKVO::On bit
}

template<>
void objects::hs::UpdateRouteTable(objects::hs &m)
{
  m.Register<bool>("status", &mapped::mOn);
}

template<>
void objects::pump::UpdateRouteTable(objects::pump &m)
{
  //m.Register("display", &mapped::Type_Flags); CPump::Work bit
}

template<>
void objects::sensor::UpdateRouteTable(objects::sensor &m)
{
  m.Register("display", &mapped::ShowValue);
}

template<>
void objects::valve::UpdateRouteTable(objects::valve &m)
{
  m.Register("closing_percentage", &mapped::VentZ); // Задание
}

template<>
void objects::gate_valve::UpdateRouteTable(objects::gate_valve &m)
{
  m.Register("closing_percentage", &mapped::VentZ);
}