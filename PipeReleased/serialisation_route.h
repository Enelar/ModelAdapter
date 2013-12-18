#include "stdafx.h"

#include "server_serialisator.h"

struct serialisation_failed
{};

template<class Tuple, int level = -1>
struct serialisation_route
{
  vector<param> operator()(const server_object_container<CShBase> obj, OBJECT_TYPES type)
  {
    static_assert(level >= 0, "Wrong template resolution");
    const int tuple_size = std::tuple_size<Tuple>::value;

    typedef std::tuple_element<level - 1, Tuple>::type selected_type;
    const int obj_id = object_id<selected_type>::tid;

    if (obj_id != type)
      return [=]()
    {
      serialisation_route<Tuple, level - 1> t;
      return t(obj, type);
    }();

    vector<param> ret;
    throw_assert(server_serializator<selected_type>(obj, ret));
    return ret;
  }
};

template<class Tuple>
struct serialisation_route<Tuple, -1>
{
  vector<param> operator()(const server_object_container<CShBase> data, OBJECT_TYPES type)
  {
    const int size = std::tuple_size<Tuple>::value;
    serialisation_route<Tuple, size> t;
    return t(data, type);
  }
};

template<class Tuple>
struct serialisation_route<Tuple, 0>
{
  vector<param> operator()(const server_object_container<CShBase> data, OBJECT_TYPES type)
  {
    throw serialisation_failed();
  }
};