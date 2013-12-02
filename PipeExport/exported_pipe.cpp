#include "exported_pipe.h"
#include <Windows.h>
#include <PipeClient.h>

exported_pipe::exported_pipe(const char *const pipe_name)
{
  pipe = new CPipeClient(pipe_name);
}

exported_pipe::~exported_pipe()
{
  delete pipe;
}

int exported_pipe::GetPipeElement( unsigned int nType,const char* szName )
{
  char strName[256];
  lstrcpy( strName, szName );
  int nNumber=pipe->FindObj(nType,szName,strName);
  return nNumber;
}