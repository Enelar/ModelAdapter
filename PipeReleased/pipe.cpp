#include "Pipe.h"
#include "../PipeExport/exported_pipe.h"

pipe::pipe()
{
  ep = new exported_pipe("aa");
}

pipe::~pipe()
{
  delete ep;
}

int pipe::GetID(ELEMENT type, std::string name)
{
  return ep->GetPipeElement(type, name.c_str());
}