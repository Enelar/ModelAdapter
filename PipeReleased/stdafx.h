#include "../AX/source/ax/def.h"
#include <string>
#include <vector>

using ax::convert;
using std::string;
using std::vector;

#ifdef PIPE_RELEASED_EXPORTS
#define PIPE_RELEASED_API __declspec(dllexport)
#else
#define PIPE_RELEASED_API __declspec(dllimport)
#endif
