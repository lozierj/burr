#include <cassert>

#include "Position.h"

class Partition{
public:
  using Type = unsigned char;
  static constexpr Type max = 1u << 5;

  Partition(Type s) : mData{s} {assert(mData < max);}

  bool IsIn(Position p) const {return (1u << p) & mData;}

private:
  Type mData;
};
