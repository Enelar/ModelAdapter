#pragma once

#include "scheme_data.h"

namespace original_source_code
{
  struct CKVOW
  {
    double Oborot;
    double Jal;
    double OborotZ;
    double VentDrainIn;
    double VentDrainOut;
  };
  struct CShKVO : public CShBase, public CFlags, public CKVOW
  {

  };
}

#include "../objects.h"

namespace objects
{
  typedef ::mapper<original_source_code::CShKVO> air_condenser;
}

template<>
void objects::air_condenser::UpdateRouteTable(objects::air_condenser &m)
{
  ////m.Register("display", &mapped::Type_Flags); CKVO::On bit
}