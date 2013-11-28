#pragma once

#include <string>

namespace asn1
{
  struct inditifier
  {
    enum CLASS;

    CLASS type_class;
    
    bool is_constructed;
    int tag_number;

    inditifier(CLASS, bool, int);
    inditifier(int);
    inditifier(std::string);

    operator std::string() const;

    static int OffsetToLength(const std::string &);
  };
};

#include "inditifier_class.h"