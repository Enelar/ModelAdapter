#include "pipe_export.h"
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