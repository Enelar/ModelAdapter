#pragma once

namespace original_source_code
{
  struct CHsW
  {
    bool mOn;
    //	int SP;
    //  int PV;
  };
}

#include "../objects.h"

namespace objects
{
  typedef ::mapper<original_source_code::CHsW> hs;
}

template<>
void objects::hs::UpdateRouteTable(objects::hs &m);