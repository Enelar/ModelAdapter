#include "scheme_data.h"
namespace original_source_code
{
  struct CPumpW
  {
    double VentIN;
    double VentOUT;
    double VentDrain;
  };
  struct CShPump : public CShBase, public CFlags, public CPumpW
  {

  };
}

#include "../objects.h"

namespace objects
{
  typedef ::mapper<original_source_code::CShPump> pump;
}

template<>
void objects::pump::UpdateRouteTable(objects::pump &m);