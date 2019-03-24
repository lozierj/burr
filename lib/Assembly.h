#pragma once

#include <array>

#include "Index.h"
#include "FitTable.h"
#include "ReflectTable.h"
#include "PointGroup.h"
#include "Position.h"

class Assembly{
public:
  Assembly() : mData{0, 0, 0, 0, 0, 0} {}
  Assembly(std::array<Index, 6> l) : mData{l} {}

  bool Fits(const FitTable&, Position) const;
  bool Oriented(const ReflectTable&, bool proper = true) const;

  const Index& operator[](Position p) const {return mData[p];}
  Index& operator[](Position p) {return mData[p];}

private:
  bool Fits(const FitTable&, Position, Position) const;
  Assembly Orient(const ReflectTable&, PointGroup) const;
  bool IsBefore(const Assembly&) const;

  std::array<Index, 6> mData;
};
