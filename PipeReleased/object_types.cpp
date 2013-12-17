#include "object_types.h"
#include "objects.h"


OBJECT_TYPES object_id<objects::valve>::tid = VALVE;
OBJECT_TYPES object_id<objects::gate_valve>::tid = GATE_VALVE;
OBJECT_TYPES object_id<objects::air_condenser>::tid = AIR_CONDENSER;
OBJECT_TYPES object_id<objects::hs>::tid = HS;
OBJECT_TYPES object_id<objects::pump>::tid = PUMP;
OBJECT_TYPES object_id<objects::sensor>::tid = SENSOR;


namespace
{
  template<typename T>
  info Extract(const mapper<T> &a)
  {
    typedef mapper<T> ported_name;
    info ret;
    auto map = a.RouteTable(). ShowMap();
    ret.is_simple = map.size() == 1;
    ret.object_type = typeid(ported_name).name();
    ret.object_type_id = object_id<ported_name>::tid;
    throw_assert(ret.object_type_id != NOTANOBJECT);

    for each (auto el in map)
    {
      param_info info;
      info.name = el.first;
      info.readonly = true;
      info.type = VALUE_TYPE::FLOAT;
      ret.params.push_back(info);
    }
    return ret;
  }

  template<typename T>
  info GenInfo(OBJECT_TYPES t)
  {
    const T m;
    return Extract(m);
  }

  template<typename T>
  std::pair<OBJECT_TYPES, info> Entry()
  {
    std::pair<OBJECT_TYPES, info> ret;
    OBJECT_TYPES type = object_id<T>::tid;
    ret.first = type;
    ret.second = GenInfo<T>(type);
    return ret;
  }
}

#include <functional>

template<typename T>
class singletone
{
  mutable T *stored = NULL;
  std::function<T *()> fabric_method;
public:
  singletone(std::function<T *()> _fabric_method)
    : fabric_method(_fabric_method)
  {
  }

  singletone() : singletone([](){ return NEW T; })
  {
  }

  T *const Access() const
  {
    if (!stored)
    {
      stored = fabric_method();
      throw_sassert(stored, "Singletone constructor return NULL");
    }
    return stored;
  }

  T &operator *() const
  {
    return *Access();
  }

  T *operator->() const
  {
    return Access();
  }

  ~singletone()
  {
    if (stored)
      delete stored;
    stored = NULL;
  }
};

template<typename T> struct generic_lambda
{
  template<typename contT>
  void operator()(contT ret)
  {
    ret->insert(Entry<T>());
  }
};

singletone<std::map<OBJECT_TYPES, info>> objects_info(
  []()
  {
    auto ret = NEW std::map<OBJECT_TYPES, info>();

    ret->insert(Entry<objects::valve>());
    ret->insert(Entry<objects::gate_valve>());
    ret->insert(Entry<objects::air_condenser>());
    ret->insert(Entry<objects::hs>());
    ret->insert(Entry<objects::pump>());
    ret->insert(Entry<objects::sensor>());
    return ret;
  }
);

const std::map<OBJECT_TYPES, info> &ObjectsInfo()
{
  return *objects_info;
}

singletone<std::vector<OBJECT_TYPES>> supported_types([]()
  {
    return NEW std::vector<OBJECT_TYPES>
    {
      VALVE,
      GATE_VALVE,
      AIR_CONDENSER,
      HS,
      PUMP,
      SENSOR
    };
  }
);

const std::vector<OBJECT_TYPES> &SupportedTypes()
{
  return *supported_types;
}