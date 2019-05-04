#pragma once

#include <vector>
#include <set>

#include "Assembly.h"
#include "Piece.h"
#include "Position.h"
#include "OffsetTable.h"

class Permutor{
public:
  Permutor(Assembly, const std::vector<Piece>&);
  void Print();
  unsigned Count() const {return mSet.size();}

private:
  void Permute(Assembly, Position);

  std::set<Assembly> mSet;
  const ReflectTable mReflect;
  const FitTable mFit;
  const EquivTable mEquiv;
  const OffsetTable mOffset;
  const std::vector<Piece> mPieces;
};
