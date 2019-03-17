#pragma once

#include <array>

#include "Index.h"
#include "FitTable.h"
#include "Position.h"

class Assembly{
public:
  bool Fits(const FitTable&, Position) const;
  const Index& operator[](Position p) const {return mData[p];}
  Index& operator[](Position p) {return mData[p];}

private:
  bool Fits(const FitTable&, Position, Position) const;

  std::array<Index, 6> mData;
};
