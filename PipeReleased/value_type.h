#pragma once

#ifndef _VALUE_TYPE_H_
#define _VALUE_TYPE_H_

#include "../PipeExport/value_types.h"

namespace pipe_released
{
  enum VALUE_TYPE
  {
    BOOL = original_source_code::enumValueBol,
    INT = original_source_code::enumValueInt,
    WORD = original_source_code::enumValueInt MAYBEWRONG,
    FLOAT = original_source_code::enumValueFlt,
    STRING = original_source_code::enumValueStr
  };
}
using namespace pipe_released;

#endif _VALUE_TYPE_H_