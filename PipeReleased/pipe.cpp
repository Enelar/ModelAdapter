#include "pipe.h"
#include "../PipeExport/exported_pipe.h"

pipe::pipe(const std::string &named_pipe)
{
  ep = new exported_pipe(named_pipe.c_str());
}

pipe::~pipe()
{
  delete ep;
}

object_interface pipe::Get(const OBJECT_TYPES type, const std::string &name)
{
  auto ObjectPostChange = [type](object_interface &obj)
  {
    auto record = ObjectsInfo().find(type);
    obj.object_info = record->second;
    return obj;
  };

  word id = GetID(type, name);
  return ObjectPostChange(Get(type, id));
}

object_interface pipe::Get(const OBJECT_TYPES type, const word id)
{
  throw_assert(id != 0);
  throw_assert(type != NOTANOBJECT);
  object_interface obj(id, type);
  return obj;
}

object_interface pipe::Get(word _id)
{
  todo(Enumerate over types and find type);
}

object_interface pipe::Get(const std::string &name)
{
  word res = 0;
  
  for each(OBJECT_TYPES type in SupportedTypes())
  {
    auto t = Get(type, name);
    if (t.GetID())
      return t;
  }
  throw_message("Object not found");
}

word pipe::GetID(const OBJECT_TYPES type, const std::string &name)
{
  return ep->GetID(type, name.c_str());
}

#include <tuple>
template<typename T>
bool Serializator(const server_object_container<typename T::mapped>, vector<param> &)
{
  IMPLEMENTATION_REQUIRED
}


template<class Tuple, int level = -1>
struct TestSerializator
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
        TestSerializator<Tuple, level - 1> t;
        return t(obj, type);
      }();

    vector<param> ret;
    throw_assert(Serializator<selected_type>(obj, ret));
    return ret;
  }
};

template<class Tuple>
struct TestSerializator<Tuple, -1>
{
  vector<param> operator()(const server_object_container<CShBase> data, OBJECT_TYPES type)
  {
    const int size = std::tuple_size<Tuple>::value;
    TestSerializator<Tuple, size> t;
    return t(data, type);
  }
};

template<class Tuple>
struct TestSerializator<Tuple, 0>
{
  vector<param> operator()(const server_object_container<CShBase> data, OBJECT_TYPES type)
  {
    return{};
  }
};

vector<param> pipe::GetRaw(const object_interface &obj)
{
  auto server_object = ep->GetServerObject(obj.id);
  typedef std::tuple<objects::valve> supported_server_objects;
  supported_server_objects t;
  
  auto ret = [=]()
  {
    TestSerializator<supported_server_objects> t;
    return t(server_object, obj.type);
  }();
  return ret;
}

void pipe::SetRaw(const object_interface &obj, vector<param> data)
{
  auto info = obj.GetInfo();
  for each (auto p in data)
  {
    throw_sassert(!info.params[1].readonly, "Write protection on this parameter");
    double t, t2;
    string server_mapped_name;
    ep->SetServerTile(obj.GetID(), server_mapped_name.c_str(), original_source_code::enumValueDbl, &t, &t2);
  }
}
