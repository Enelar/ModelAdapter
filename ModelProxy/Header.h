#ifdef MODELPROXY_EXPORTS
#define PROXY_API __declspec(dllexport)
#else
#define PROXY_API __declspec(dllimport)
#endif

#include "../PipeReleased/pipe.h"

struct object
{
  mutable object_interface *obj;

  object(object_interface *_obj)
    : obj(_obj)
  {

  }

  object(const object &a)
    : obj(nullptr)
  {
    ax::Swap(a.obj, obj);
  }

  ~object()
  {
    if (obj)
      delete obj;
  }
};


PROXY_API int Construct();
PROXY_API void Destruct(int);
PROXY_API void DestructObject(int);

PROXY_API int Get(int, const char *str);
PROXY_API int Get(int, int);
PROXY_API int GetID(int, const char *str);

PROXY_API double GetDouble(int, int);
PROXY_API double GetDouble(int, const char *);
PROXY_API double GetSimpleDouble(int);

PROXY_API void SetDouble(int, int, double);

struct model
{
  model();
  ~model();

  object Get(const char *str);
  object Get(int);
  int GetID(const char *str);

private:
  pipe::store_type *p;
  pipe::store_type Pipe() const;
};