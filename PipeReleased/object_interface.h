#include "stdafx.h"

class object_interface
{
  word id;
  object_interface();
  friend class pipe;
public:
  word GetID() const;
};