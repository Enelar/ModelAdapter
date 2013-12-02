#ifdef TVRPROXY_EXPORTS
#define _API __declspec(dllexport)
#else
#define _API __declspec(dllimport)
#endif


class CPipeClient; // original
class _API exported_pipe
{
  CPipeClient *pipe;

public:
  // crap code, but cant compile in other way, because of `nan` name conflict
  exported_pipe(const char *const pipe_name);
  virtual ~exported_pipe();

public:
  int GetPipeElement( unsigned int nType,const char* szName );
};