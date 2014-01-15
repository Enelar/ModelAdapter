#include "../ASN1/ASN1/asn1.h"

#include "../ASN1/ASN1/internal_header.h"

using namespace asn1;
REFACTOR
struct dummy_double : asn1::entity
{
  double t;
  dummy_double(double _t)
    : entity(asn1::inditifier(inditifier::APPLICATION, false, VALUE_TYPE::FLOAT)), t(_t)
  {

  }

  operator std::string() const
  {
    string ret;

    ConCat(ret, type);
    ConCat(ret, EncodeLength());

    const entity::byte *_content = reinterpret_cast<const entity::byte *>(&t);
    for (word i = 0; i < sizeof(t); i++)
      ret += _content[i];
    return ret;
  }

  operator double &()
  {
    return t;
  }

  operator double () const
  {
    return t;
  }

  int Length() const
  {
    return sizeof(double);
  }

  LENGTH_TYPE LengthType() const
  {
    return LENGTH_TYPE::DEFINITE;
  }
};