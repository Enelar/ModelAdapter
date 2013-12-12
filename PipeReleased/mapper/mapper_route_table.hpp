#define _MAPPER_ROUTE_TABLE_IMPL
#include "mapper_route_table.h"

#define __TEMPLATE_HEAD__ template<typename OriginT>
#define __TEMPLATE_CLASS__ mapper_route<OriginT>
#define __TEMPLATE_MACROS(code) __TEMPLATE_HEAD__ \
  code __TEMPLATE_CLASS__
#define __TEMPLATE__ __TEMPLATE_MACROS(auto)
#define __TEMPLATE_SPECIAL__ __TEMPLATE_MACROS()
#define __TEMPLATE_METHOD(additional_template_agruments) __TEMPLATE_MACROS(template< additional_template_agruments > \
  auto)

__TEMPLATE_METHOD(typename T)::Register(string name, T OriginT::*ref) -> word
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

__TEMPLATE__::Info(word) const -> param_info
{
  todo(Info);
}

__TEMPLATE_METHOD(typename T)::GetRef(word id) const -> T OriginT::*
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

__TEMPLATE__::GetID(string name) const -> word
{
  auto pair = ids.find(name);
  return pair->second;
}

__TEMPLATE__::ShowMap() const -> std::map<string, param_info>
{
  std::map<string, param_info> info;
  for each (auto var in names)
    info.insert({ var.second, { var.second, true, FLOAT } });
  return info;
}
