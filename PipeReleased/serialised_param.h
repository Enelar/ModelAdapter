#include "stdafx.h"
#include "value_type.h"

struct serialised_param
{
  VALUE_TYPE t;
  string asn1_encoded_string;
};