#include <functional>
using std::function;

class CPipeClient; // original
typedef void *handle;
class exported_pipe
{
  CPipeClient *pipe;
  handle library;

public:
  // crap code, but cant compile in other way, because of `nan` name conflict
  exported_pipe(const char *const pipe_name);
  virtual ~exported_pipe();

private:
  function<void(const char *)> constructor;
  function<void()> destructor;
};