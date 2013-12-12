#include "object_types.h"
#include "objects.h"

std::vector<OBJECT_TYPES> supported_types = {
  VALVE,
  GATE_VALVE,
  AIR_CONDENSER,
  HS,
  PUMP,
  SENSOR
};

OBJECT_TYPES object_id<objects::valve>::tid = VALVE;
OBJECT_TYPES object_id<objects::gate_valve>::tid = GATE_VALVE;
OBJECT_TYPES object_id<objects::air_condenser>::tid = AIR_CONDENSER;
OBJECT_TYPES object_id<objects::hs>::tid = HS;
OBJECT_TYPES object_id<objects::pump>::tid = PUMP;
OBJECT_TYPES object_id<objects::sensor>::tid = SENSOR;


namespace
{
  template<typename T>
  info Extract(const mapper_route<T> &a)
  {
    info ret;
    auto map = a.ShowMap();
    ret.is_simple = map.size() == 1;
    ret.object_type = typeid(T).name();
    ret.object_type_id = object_id<T>::tid;
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
    return Extract(m.RouteTable());
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

std::map<OBJECT_TYPES, info> objects_info = {
  Entry<objects::valve>(),
  Entry<objects::gate_valve>(),
  Entry<objects::air_condenser>(),
  Entry<objects::hs>(),
  Entry<objects::pump>(),
  Entry<objects::sensor>(),
};