#define _MAPPER_ROUTE_TABLE_IMPL
#include "mapper_route_table.h"

template<typename OriginT>
template<typename T>
word mapper_route<OriginT>::Register(string name, T OriginT::*)
{
  todo(Register);
}

template<typename OriginT>
param_info mapper_route<OriginT>::Info(word) const
{
  todo(Info);
}

template<typename OriginT>
template<typename T>
T OriginT::* mapper_route<OriginT>::GetRef(word) const
{
  todo(GetRef);
}

template<typename OriginT>
word mapper_route<OriginT>::GetID(string) const
{
  todo(GetID);
}
