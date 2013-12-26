// ExceptionSafeDebug.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../ExceptionSafeModel/ExceptionSafeModel.h"


int _tmain(int argc, _TCHAR* argv[])
{
  int model = 0;
  ERROR_CODES code;
  model = NEConstruct();
  char exception[100];
//  auto ch = GetLastExceptionString(exception, 100);
  int obj = NEGet(model, L"Z-15");
  //ch = 
  wchar_t str[100];
  auto ch = GetLastExceptionString(str, 100);
  while (1)
  {
    double d = NEGetDouble(obj, 0);
    printf("%lf\n", d);
  }
  NEDestructObject(obj);
  NEDestruct(model);
  //code = (ERROR_CODES)NEConstruct(&model);
  //code = (ERROR_CODES)NEDestruct(model);
  //code = (ERROR_CODES)NEGet(&model, model, nullptr);
	return 0;
}

