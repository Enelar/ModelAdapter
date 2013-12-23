#include "Header.h"

#define MOD reinterpret_cast<model *>(obj)
#define OBJ reinterpret_cast<object *>(obj)->obj

PROXY_API int Construct()
{
  return reinterpret_cast<int>(NEW MEMLEAK model());
}

int Export(object t)
{
  return reinterpret_cast<int>(NEW MEMLEAK object(t));
}

PROXY_API void Destruct(int obj)
{
  delete reinterpret_cast<model *>(obj);
}

PROXY_API void DestructObject(int obj)
{
  delete reinterpret_cast<object *>(obj);
}


PROXY_API int Get(int obj, const char *str)
{
  return Export(MOD->Get(str));
}

PROXY_API int Get(int obj, int id)
{
  return Export(MOD->Get(id));
}

PROXY_API int GetID(int obj, const char *str)
{
  return MOD->GetID(str);
}


PROXY_API double GetDouble(int obj, int id)
{
  auto t = OBJ->GetParam(id);
  double d = *reinterpret_cast<const double *>(t.asn1_encoded_string.c_str() + 2);
  return d;
}

PROXY_API double GetDouble(int obj, const char *name)
{
  return 0;
}

PROXY_API double GetSimpleDouble(int obj)
{
  return GetDouble(obj, 0);
}