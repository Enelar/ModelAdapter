#define _MAPPER_ROUTE_TABLE_IMPL
#include "mapper_route_table.h"


template<typename OriginT>
template<typename T>
word mapper_route<OriginT>::Register(string name, T OriginT::*ref)
{
#ifdef REFACTOR
  static_assert(std::is_same<T, double>::value, "Multitype implementation required");
#endif
  auto Offset = [ref]()
  {
    auto mem = reinterpret_cast<const void *>(&ref);
    auto pre = convert<const word *const>(mem);
    return *pre;
  };

  offsets.insert(std::pair<string, word>(name, Offset()));
  ids.insert(std::pair<string, word>(name, ++last_id));
  names.insert(std::pair<word, string>(last_id, name));
  return last_id;
}

template<typename OriginT>
param_info mapper_route<OriginT>::Info(word) const
{
  todo(Info);
}

template<typename OriginT>
template<typename T>
T OriginT::* mapper_route<OriginT>::GetRef(word id) const
{
  auto name = names.find(id)->second;
  word offset = offsets.find(name)->second;

  auto Convert = [offset]()
  {
    typedef T (OriginT::*my_t);
    auto pre = convert<const word *const>(&offset);
    auto mem = reinterpret_cast<const void *>(pre);
    const my_t ret = *reinterpret_cast<const my_t *>(mem);
    return ret;
  };
  return Convert();
}

template<typename OriginT>
word mapper_route<OriginT>::GetID(string name) const
{
  auto pair = ids.find(name);
  return pair->second;
}
