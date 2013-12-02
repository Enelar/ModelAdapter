#include <string>
#include "object_types.h"
#include "object_interface.h"

class exported_pipe;
class pipe
{
  exported_pipe *ep;
public:
  pipe();
  virtual ~pipe();
  object_interface Get(OBJECT_TYPES type, std::string name);
  object_interface Get(word id);
private:
  word GetID(OBJECT_TYPES type, std::string name);
};