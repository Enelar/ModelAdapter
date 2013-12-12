#pragma once

#include "stdafx.h"
#include "param_info.h"

struct info
{
  string object_type;
  word object_type_id;
  bool is_simple;
  vector<param_info> params;
};