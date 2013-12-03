#define _MAPPER_IMPL_

#include "mapper.h"
#include "mapper_route_table.h"

template<typename OriginT>
template<typename T>
word mapper<OriginT>::Register(string name, T OriginT::*ref)
{
  return RouteTable().Register<T>(name, ref);
}

template<typename OriginT>
param_info mapper<OriginT>::Info(word id) const
{
  return RouteTable().Info(id);
}

template<typename OriginT>
param mapper<OriginT>::operator[](word) const
{
  todo(Mapper operator []);
}

template<typename OriginT>
template<typename T>
T mapper<OriginT>::Get(word id) const
{
  return IntAccess(id);
}

template<typename OriginT>
template<typename T>
T mapper<OriginT>::Get(string name) const
{
  word id = RouteTable().GetID(name);
  return Get(id);
}

template<typename OriginT>
template<typename T>
void mapper<OriginT>::Set(word id, const T& data)
{
  IntAccess(id) = data;
}

template<typename OriginT>
template<typename T>
void mapper<OriginT>::Set(string name, const T&data)
{
  word id = RouteTable().GetID(name);
  Set(id, data);
}

template<typename OriginT>
void mapper<OriginT>::Platform(OriginT *platform) const
{
  observee = platform;
}

template<typename OriginT>
void mapper<OriginT>::Validate() const
{
  throw_assert(observee != nullptr);
}

template<typename OriginT>
mapper_route<OriginT> &mapper<OriginT>::RouteTable()
{
  if (!route_table)
    route_table = NEW mapper_route();
  return route_table;
}

template<typename OriginT>
const mapper_route<OriginT> &mapper<OriginT>::RouteTable() const
{
  if (!route_table)
    route_table = NEW mapper_route();
  return route_table;
}

template<typename OriginT>
template<typename T>
T &mapper<OriginT>::IntAccess(word)
{
  T OriginT::* ref = RouteTable().GetRef(id);
  Validate();
  return observee->*ref;
}

template<typename OriginT>
template<typename T>
T &mapper<OriginT>::IntAccess(word) const
{
  T OriginT::* ref = RouteTable().GetRef(id);
  Validate();
  return observee->*ref;
}