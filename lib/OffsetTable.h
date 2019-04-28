#pragma once

#include <array>
#include <vector>

#include "Index.h"
#include "Piece.h"
#include "PointGroup.h"
#include "Position.h"
#include "ReflectTable.h"
#include "Rotate.h"
#include "Translate.h"

class OffsetTable{
public:
  OffsetTable(const std::vector<Piece>&, const ReflectTable&);
  bool operator()(
      Index ai, Position ap, Index bi, Position bp,
      Translate offset) const;

private:
  bool Perp(Index, Index, Translate, PointGroup) const;
  bool Para(Index, Index, Translate, Rotate) const;

  using LocalPerp = std::array<std::array<std::array<bool,  7>, 3>, 7>;
  using LocalPara = std::array<std::array<std::array<bool, 11>, 3>, 3>;
  std::vector<std::vector<LocalPerp>> mPerp;
  std::vector<std::vector<LocalPara>> mPara;

  const ReflectTable& mRef;
};
