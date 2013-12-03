#pragma once
#include "stdafx.h"
#include "param_info.h"
#include <map>

template<typename OriginT>
class mapper_route
{
public:
  template<typename T>
  word Register(string name, T OriginT::*);
  param_info Info(word) const;

  template<typename T>
  T OriginT::*GetRef(word) const;
  word GetID(string) const;
private:
  word last_id = 0;
  std::map<string, word> offsets, ids;
  std::map<word, string> names;
};

#ifndef _MAPPER_ROUTE_TABLE_IMPL
#include "mapper_route_table.hpp"
#endif