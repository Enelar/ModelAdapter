#include "header.h"

#include "server_object_container.h"
#include "value_types.h"


class CPipeClient; // original
struct CShBase;

class _API exported_pipe
{
  CPipeClient *pipe;

public:
  // crap code, but cant compile in other way, because of `nan` name conflict
  exported_pipe(const char *const pipe_name);
  virtual ~exported_pipe();

  //int GetID( const char *name ) const;
  int GetID( unsigned int type, const char *name ) const;

public:
  void Update();
  server_object_container<CShBase> GetServerObject( unsigned int id ) const;
  void SetServerTile( unsigned int id, const char *parameter_name, original_source_code::EValueType type, const void *value, const void *prev ); 
};