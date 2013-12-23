#ifdef TVRPROXY_EXPORTS
#define _API __declspec(dllexport)
#else
#define _API __declspec(dllimport)
#endif