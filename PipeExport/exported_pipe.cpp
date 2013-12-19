#include "exported_pipe.h"
#include <Windows.h>
#include <PipeClient.h>

exported_pipe::exported_pipe(const char *const pipe_name)
{
  pipe = new CPipeClient(pipe_name);
}

void exported_pipe::Update()
{
  pipe->Refresh();
}

exported_pipe::~exported_pipe()
{
  pipe->End();
  delete pipe;
}
/*
int exported_pipe::GetID( const char *name )
{
  return 0;
}
*/

int exported_pipe::GetID( unsigned int nType, const char* szName ) const
{
  char strName[256];
  lstrcpy( strName, szName );
  int nNumber=pipe->FindObj(nType,szName,strName);
  return nNumber;
}

namespace
{
  template<typename T>
  T *new_without_constructor_call()
  {
    struct memory_block
    {
      unsigned char mem[sizeof(T)];
    };
    int static_assert[sizeof(memory_block) >= sizeof(T) ? 1 : -1];
    static_assert[0] = 0;
    return reinterpret_cast<T *>(new memory_block());
  }
  template<typename T>
  T *new_without_constructor_call( int size )
  {
    struct memory_block
    {
      unsigned char mem[sizeof(T)];
    };
    int static_assert[sizeof(memory_block) >= sizeof(T) ? 1 : -1];
    static_assert[0] = 0;
    return reinterpret_cast<T *>(new memory_block());
  }
}

server_object_container<CShBase> exported_pipe::GetServerObject( unsigned int id ) const
{
  CShBase *obj = pipe->Sh(id);
  return server_object_container<CShBase>(*obj, obj->m_nSize);
}

void exported_pipe::SetServerTile( unsigned int id, const char *parameter_name, original_source_code::EValueType type, const void *value, const void *prev )
{
  if (!id)
    return;
  SSendToModel send;
  size_t len = strlen(parameter_name);
  if (len >= sizeof(send.szValue) / sizeof(send.szValue[0]))
    return;
  memcpy(send.szValue, parameter_name, len + 1);
  send.Set(static_cast<::EValueType>(type), prev, value);
  pipe->SendData(id, send);
}