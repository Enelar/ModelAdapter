#include <string>
#include "object_types.h"
#include "object_interface.h"

class exported_pipe;
class pipe
{
  exported_pipe *ep;
public:
  pipe() : pipe("Главная")
  {}
  pipe(const std::string &named_pipe);
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