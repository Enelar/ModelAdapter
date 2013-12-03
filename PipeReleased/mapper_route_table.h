#pragma once
#include "stdafx.h"
#include "param_info.h"

template<typename OriginT>
class mapper_route
{
public:
  template<typename T>
  word Register(string name, T OriginT::*);
  param_info Info(word) const;

  template<typename T>
  T OriginT::*GetRef(word);
  word GetID(string);
};

#ifndef _MAPPER_ROUTE_TABLE_IMPL
#include "mapper_route_table.hpp"
#endif