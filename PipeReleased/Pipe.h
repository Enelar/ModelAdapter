enum ELEMENT
{
  TEST = 12
};

#include <string>

class exported_pipe;
class pipe
{
  exported_pipe *ep;
public:
  pipe();
  virtual ~pipe();
  int GetID(ELEMENT, std::string name);
};