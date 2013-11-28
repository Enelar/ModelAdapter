class CPipeClient; // original
class exported_pipe
{
  CPipeClient *pipe;

public:
  // crap code, but cant compile in other way, because of `nan` name conflict
  exported_pipe(const char *const pipe_name);
  virtual ~exported_pipe();
};