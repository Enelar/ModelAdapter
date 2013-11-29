#include "entity.h"
#include "internal_header.h"
#include <list>

using namespace asn1;
using std::string;
using std::list;

entity::entity(inditifier _type)
: type(_type)
{

}

namespace
{
  const int length_content_in_octet = BITSINBYTE - 1;
}


string entity::EncodeLength(word length) const
{
  auto ToString = [](const std::vector<ub> &a)
  {
    std::string t;
    for each (ub ch in a)
      t.push_back(ch);
    return t;
  };
  if (length < 128)
    return ToString({ convert<ub>(length) });
  std::vector<ub> t;
  while (length != 0)
  {
    ub temp = length & GETMAXVALUE(length_content_in_octet);
    temp |= GETMAXCOUNT(length_content_in_octet);
    t.push_back(temp);
    length >>= length_content_in_octet;
  }
  std::reverse(t.begin(), t.end());
  return ToString(t);
}

string entity::EncodeLength() const
{
  return EncodeLength(Length());
}

string entity::EncodeConstructed(word chunk_max_size, const string &source)
{
#define FORCE_INDEFINITE_FORM // require for CER encoding
  auto GetHeader = [this, source]()
  {
    auto GetConstructedInditifier = [this]()
    {
      inditifier constructed(this->type);
      constructed.is_constructed = true;
      return convert<string>(constructed);
    };
    auto ret = GetConstructedInditifier();
#ifndef FORCE_INDEFINITE_FORM
    ConCat(ret, EncodeLength());
#else
    ret.push_back(GETMAXCOUNT(length_content_in_octet));
#endif
    return ret;
  };
  auto header = GetHeader();
  auto source_copy = source;
  std::vector<string> chunks;

  while (source_copy.length())
  {
    string chunk = type;
    word write_data = ax::Min(source_copy.length(), chunk_max_size);
    ConCat(chunk, EncodeLength(write_data));
    ConCat(chunk, source_copy, write_data);
    source_copy = Shift(source_copy, write_data);
  }

  if (chunks.size() == 1)
    return chunks[0];

  std::list<string> oper(std::make_move_iterator(chunks.begin()), std::make_move_iterator(chunks.end()));

  while (oper.size())
  {
    ConCat(header, oper.front());
    oper.pop_front();
  }
  header.push_back(0);
  header.push_back(0);
  return header;
}