#pragma once

#ifndef _MAPPER_H_
#define _MAPPER_H_

#include "stdafx.h"
#include "param_info.h"
#include "param.h"

template<typename OriginT>
class mapper_route;

template<typename OriginT>
class mapper
{
public:
  template<typename T>
  word Register(string name, T OriginT::*);
  param_info Info(word) const;
  param operator[](word) const;

  template<typename T>
  T Get(word) const;
  template<typename T>
  T Get(string) const;

  template<typename T>
  void Set(word, const T&);
  template<typename T>
  void Set(string, const T&);

  void Platform(OriginT *) const;
private:
  void Validate() const;
  mutable OriginT *observee = nullptr;

  mutable mapper_route<OriginT> *route_table = nullptr;
  mapper_route<OriginT> &RouteTable();
  const mapper_route<OriginT> &RouteTable() const;

  template<typename T>
  T &IntAccess(word);
  template<typename T>
  T &IntAccess(word) const;

  static void UpdateRouteTable(mapper &);
};

#ifndef _MAPPER_IMPL_
#include "mapper.hpp"
#endif

#endif