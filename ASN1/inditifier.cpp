#include "inditifier.h"

using namespace asn1;

inditifier::inditifier(CLASS _type_class, bool _constructed, int _type_oid )
: type_class(_type_class), is_constructed(_constructed), tag_number(_type_oid)
{

}

inditifier::inditifier(int _type_oid)
: inditifier(inditifier::UNIVERSAL, false, _type_oid)
{

}

inditifier::inditifier(std::string str)
{
}

inditifier::operator std::string() const
{

}

int inditifier::OffsetToLength(const std::string &)
{

}