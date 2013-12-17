#pragma once

#include "stdafx.h"
#include "info.h"
#include "param.h"

class object_interface
{
  word id;
  OBJECT_TYPES type;
  info object_info;
  object_interface(word, OBJECT_TYPES);
  friend class pipe;
public:
  word GetID() const;
  info GetInfo() const;

  void SetSimpleParam(serialised_param);
  void SetParam(word param, serialised_param value);
  void SetParam(param);

  serialised_param GetSimpleParam() const;
  serialised_param GetParam(word param) const;

  void SetBundle(vector<param> data);
  vector<param> GetBundle() const;
};