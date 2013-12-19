#pragma once

#include <string>
#include "object_types.h"
#include <memory>

class object_interface;
class exported_pipe;
class pipe
{
public:
  typedef std::shared_ptr<pipe> store_type;
private:
  store_type *ref;
  exported_pipe *ep;
  bool shutdowned = false;
  store_type &Ref() const;
  friend class object_interface;
private:
  pipe() : pipe("Главная")
  {}
  pipe(const std::string &named_pipe);
public:
  void Shutdown();
  static store_type Make();
  
  virtual ~pipe();
  object_interface Get(const OBJECT_TYPES type, const std::string &name);
  object_interface Get(const std::string &name);
private: // In case of desync temporary unavaible
  object_interface Get(const OBJECT_TYPES type, const word id);
  object_interface Get(const word id);
private:
  word GetID(const OBJECT_TYPES type, const std::string &name);
public:
  info GetInfoByObjectType(const OBJECT_TYPES type);

  vector<param> GetRaw( const object_interface & );
  void SetRaw(const object_interface &, vector<param>);
};

#include "object_interface.h"
