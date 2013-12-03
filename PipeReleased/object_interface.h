#include "stdafx.h"
#include "info.h"
#include "param.h"

class object_interface
{
  word id;
  info object_info;
  object_interface();
  friend class pipe;
public:
  word GetID() const;
  info GetInfo() const;

  template<typename T>
  void SetSimpleParam(T value);
  template<typename T>
  void SetParam(word param, T value);

  template<typename T>
  T GetSimpleParam() const;
  template<typename T>
  T GetParam(word param) const;

  void SetBundle(vector<param> data);
  vector<param> GetBundle() const;

};