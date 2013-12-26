#pragma once

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the EXCEPTIONSAFEMODEL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// EXCEPTIONSAFEMODEL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef EXCEPTIONSAFEMODEL_EXPORTS
#define EXCEPTIONSAFEMODEL_API __declspec(dllexport)
#else
#define EXCEPTIONSAFEMODEL_API __declspec(dllimport)
#endif

// This class is exported from the ExceptionSafeModel.dll
class EXCEPTIONSAFEMODEL_API CExceptionSafeModel {
public:
	CExceptionSafeModel(void);
	// TODO: add your methods here.
};

extern EXCEPTIONSAFEMODEL_API int nExceptionSafeModel;

EXCEPTIONSAFEMODEL_API int fnExceptionSafeModel(void);


EXCEPTIONSAFEMODEL_API enum ERROR_CODES
{
  SUCCESS = 0,
  OBJECT_NOT_FOUND = 1,
  INVALID_RETURN_ARGUMENT = 2,
  INVALID_ARGUMENT = 3,
  ASSERT_FAULT = 4,
  EXCEPTION = 5,
  DLL_NOT_FOUND = 239,

  TODO = 444
};

EXCEPTIONSAFEMODEL_API int NEConstruct();
EXCEPTIONSAFEMODEL_API void NEDestruct(int obj);
EXCEPTIONSAFEMODEL_API void NEDestructObject(int obj);
EXCEPTIONSAFEMODEL_API int NEGet(int obj, const wchar_t *str);
EXCEPTIONSAFEMODEL_API int NEGet(int obj, int id);
EXCEPTIONSAFEMODEL_API int NEGetID(int obj, const char *str);
EXCEPTIONSAFEMODEL_API double NEGetDouble(int obj, int id);
EXCEPTIONSAFEMODEL_API double NEGetDouble(int obj, const char *name);
EXCEPTIONSAFEMODEL_API double NEGetSimpleDouble(int obj);
EXCEPTIONSAFEMODEL_API int Status();
EXCEPTIONSAFEMODEL_API bool GetLastExceptionString( char *, int );
EXCEPTIONSAFEMODEL_API bool GetLastExceptionString(wchar_t *, int);

EXCEPTIONSAFEMODEL_API void NESetDouble(int obj, int id, double);