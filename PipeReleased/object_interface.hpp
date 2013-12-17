#pragma once

#include "object_interface.h"

template<typename T>
void object_interface::SetSimpleParam(T value)
{
  SetParam(0, value);
}

template<typename T>
void object_interface::SetParam(word param, T value)
{
  todo("Bind this to model");
}

template<typename T>
T object_interface::GetSimpleParam() const
{
  return GetParam(0);
}

template<typename T>
T object_interface::GetParam(word param) const
{
  todo("Bind this to model");
}