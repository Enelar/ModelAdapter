#include "stdafx.h"
#include "../ModelProxy/Header.h"

static HINSTANCE lib;
static HMODULE DLL;
EXCEPTIONSAFEMODEL_API ERROR_CODES status;
std::string exceptionstr;

static decltype(&Construct) _Construct;
static decltype(&Destruct) _Destruct;
static decltype(&DestructObject) _DestructObject;

static int(*_Get)(int, int);
static int(*_GetByStr)(int, const char *);
//PROXY_API int Get(int, int);
static decltype(&GetID) _GetID;

static double(*_GetDouble)(int, int);
static double(*_GetDoubleByStr)(int, const char *);
static decltype(&GetSimpleDouble) _GetSimpleDouble;

#define AUTO_CAST(var) var = (decltype(var))
#define EXPORT(func, spec) AUTO_CAST(GLUE(_,func))(GetProcAddress(DLL, "?" TOSTRING(func) "@@" spec "@Z")); if (!GLUE(_,func)) printf("%i CantLoad " TOSTRING(func) "\n", GetLastError())


bool LoadDll()
{
  if (!SetDllDirectory(L"W:/ModelDLL/"))
    return 0;
  //AddDllDirectory(L"W:/documents/GitHub/TSOFT_ModelAdapter/Debug/");
  lib = LoadLibrary(L"ModelProxy.dll");
  DLL = GetModuleHandle(L"ModelProxy.dll");
    //
  if (!DLL)
    status = DLL_NOT_FOUND;

  AUTO_CAST(_Construct)(GetProcAddress(DLL, "?Construct@@YAHXZ"));
  EXPORT(Destruct, "YAXH");
  EXPORT(DestructObject, "YAXH");
  EXPORT(GetID, "YAHHPBD");
  EXPORT(GetSimpleDouble, "YANH");

  AUTO_CAST(_Get)(GetProcAddress(DLL, "?Get@@YAHHH@Z"));
  AUTO_CAST(_GetByStr)(GetProcAddress(DLL, "?Get@@YAHHPBD@Z"));
  EXPORT(GetDouble, "YANHH");
  AUTO_CAST(_GetDoubleByStr)(GetProcAddress(DLL, "?GetDouble@@YAHHPBD@Z"));

  return !!DLL;
}

bool UnloadDll()
{
  return FreeLibrary(DLL);
}

#define CHECK_RETURN(a) if (!(a)) status = INVALID_RETURN_ARGUMENT;
#define TRY_BLOCK(Call) try { Call; } CATCH_BLOCK 
#define CATCH_BLOCK \
  catch (const ax::ax_exception &a) \
{ \
  status = ERROR_CODES::ASSERT_FAULT; \
  exceptionstr = a.GetString(); \
} \
catch (...) \
{ status = ERROR_CODES::EXCEPTION;  } 

#include "ExceptionSafeModel.h"

void Log(const char *str)
{
  FILE *F;
  if (fopen_s(&F, "proxy.log", "wt"))
    return;
  fprintf(F, "\n");
  auto hex = [](ub ch)
  {
    auto hex = [](ub ch)
    {
      throw_assert(ch >= 0);
      if (ch < 0xA)
        return '0' + ch;
      throw_assert(ch < 0x10);
      return ch + 'A' - 0xA;
    };
    string ret = "\\x";
    ret += hex(ch >> 4);
    ret += hex(ch & 15);
    return ret;
  };

  for (int i = 0; i < 100; i++)
    fprintf(F, "%s", hex(str[i]).c_str());
  fprintf(F, "\n");
  fflush(F);
  fclose(F);
}

using std::wstring;

template<>
string convert(const wstring &a)
{
  string ret;
  word i = 0;
  while (i < a.length())
    ret += convert<char>(a[i++]);
  return ret;
}

template<>
wstring convert(const string &a)
{
  wstring ret;

  word i = 0;
  while (i < a.length())
    ret += convert<wchar_t>(a[i++]);
  return ret;
}

EXCEPTIONSAFEMODEL_API int NEConstruct()
{
  if (status) return 0;
  TRY_BLOCK(return _Construct())
  return 0;
}

EXCEPTIONSAFEMODEL_API void NEDestruct(int obj)
{
  if (status) return;
  TRY_BLOCK(_Destruct(obj))
}

EXCEPTIONSAFEMODEL_API void NEDestructObject(int obj)
{
  if (status) return;
  TRY_BLOCK(_DestructObject(obj))
}


EXCEPTIONSAFEMODEL_API int NEGet(int obj, const wchar_t *str)
{
  if (status) return 0;
  auto pass = convert<string, wstring>(str);
  Log(pass.c_str());
  exceptionstr = convert<string, wstring>(str);
  TRY_BLOCK(return _GetByStr(obj, pass.c_str()))
  return 0;
}

EXCEPTIONSAFEMODEL_API int NEGet(int obj, int id)
{
  if (status) return 0;
  TRY_BLOCK(return _Get(obj, id))
  return 0;
}

EXCEPTIONSAFEMODEL_API int NEGetID(int obj, const char *str)
{
  if (status) return 0;
  TRY_BLOCK(return _GetID(obj, str));
  return 0;
}


EXCEPTIONSAFEMODEL_API double NEGetDouble(int obj, int id)
{
  if (status) return 0;
  TRY_BLOCK(return _GetDouble(obj, id))
  return 0;
}

EXCEPTIONSAFEMODEL_API double NEGetDouble(int obj, const char *name)
{
  if (status) return 0;
  TRY_BLOCK(return _GetDoubleByStr(obj, name))
  return 0;
}

EXCEPTIONSAFEMODEL_API double NEGetSimpleDouble(int obj)
{
  if (status) return 0;
  return NEGetDouble(obj, 0);
}

EXCEPTIONSAFEMODEL_API int Status()
{
  return status;
}

EXCEPTIONSAFEMODEL_API bool GetLastExceptionString(char *buf, int max_len)
{
  if (buf == nullptr)
  {
    status = INVALID_RETURN_ARGUMENT;
    return false;
  }
  if (max_len < 1)
  {
    status = INVALID_ARGUMENT;
    return false;
  }
  REFACTOR //ax::StrCopy(buf, exceptionstr.c_str(), max_len);
  auto src = exceptionstr.c_str();
  strcpy_s(buf, max_len, src);
  return exceptionstr != "";
}

EXCEPTIONSAFEMODEL_API bool GetLastExceptionString(wchar_t *buf, int max_len)
{
  if (buf == nullptr)
  {
    status = INVALID_RETURN_ARGUMENT;
    return false;
  }
  if (max_len < 1)
  {
    status = INVALID_ARGUMENT;
    return false;
  }
  REFACTOR //ax::StrCopy(buf, exceptionstr.c_str(), max_len);
    auto src = exceptionstr.c_str();
  while (max_len && (*buf++ = *src++))
    max_len--;
  return exceptionstr != "";
}