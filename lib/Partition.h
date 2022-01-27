#pragma once

#include <cassert>

#include "Position.h"

class Partition{
public:
  using Type = unsigned char;

  Partition(Type s) : mData{s} {assert(mData < (1u << 6));}

  bool IsIn(Position p) const;
  bool ThreeAxes() const;
  bool IsSubset(Partition) const;
  bool IsSingle() const;
  Partition Complement(Partition) const;
  unsigned First() const;

  void RotateXZ();
  void operator++() {++mData;}

  static Partition All() {return 077u;}

  Type Get() const {return mData;}

private:
  Type mData;
};
