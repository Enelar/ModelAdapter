#include "server_object_container.h"

void _API InDLLDestruct( void *a )
{
  delete []a;
}

_API unsigned char *InDLLConstruct( int size )
{
  return new unsigned char[size];
}