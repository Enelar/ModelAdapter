// ExceptionSafeModel.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ExceptionSafeModel.h"


// This is an example of an exported variable
EXCEPTIONSAFEMODEL_API int nExceptionSafeModel=0;

// This is an example of an exported function.
EXCEPTIONSAFEMODEL_API int fnExceptionSafeModel(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see ExceptionSafeModel.h for the class definition
CExceptionSafeModel::CExceptionSafeModel()
{
	return;
}
