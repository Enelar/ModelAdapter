#ifdef TVRPROXY_EXPORTS
#define _API __declspec(dllexport)
#else
#define _API __declspec(dllimport)
#endif

#include "server_object_container.h"


class CPipeClient; // original
struct CShBase;

class _API exported_pipe
{
  CPipeClient *pipe;

public:
  // crap code, but cant compile in other way, because of `nan` name conflict
  exported_pipe(const char *const pipe_name);
  virtual ~exported_pipe();

public:
  void Update();
  int GetPipeElement( unsigned int nType,const char* szName );
  server_object_container<CShBase> GetServerObject( unsigned int id ) const;
};