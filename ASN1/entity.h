#pragma once

#include "inditifier.h"
#include <vector>
namespace asn1
{
  struct entity
  {
  protected:
    typedef unsigned char byte;
    inditifier type;

    entity(inditifier type);
  public:
    virtual operator std::string() const = 0;
    virtual int Length() const = 0;

    enum LENGTH_TYPE
    {
      DEFINITE,
      INDEFINITE
    };
    virtual LENGTH_TYPE LengthType() const = 0;
    virtual ~entity() = default;

  protected:
    std::string EncodeLength(word length) const;
    std::string EncodeLength() const;
    std::string EncodeConstructed(word chunk_max_size, const std::string &source);
  };
};