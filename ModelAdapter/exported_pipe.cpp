#include "exported_pipe.h"

#define _VS12_
#include <Windows.h>
#include <PipeClient.h>

typedef void(*tShowErrors)(int Level, char * Fmt, ...);
extern tShowErrors pShowErrors;

exported_pipe::exported_pipe(const char *const pipe_name)
{                     /*
  HMODULE h = LoadLibrary("MnemoWnd.dll");
  library = h;

  typedef void(*construct)(const char *);
  construct t = (construct)GetProcAddress(h, "CPipeClient::CPipeClient");
  constructor = t;
                    */
  pipe = new CPipeClient(pipe_name);
}

exported_pipe::~exported_pipe()
{
  //delete pipe;
}