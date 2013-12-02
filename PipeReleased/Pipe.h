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
  object_interface Get(const word id);
private:
  word GetID(const OBJECT_TYPES type, const std::string &name);
};