#pragma once

#include <array>
#include <vector>

#include "Index.h"
#include "Piece.h"
#include "Position.h"

class FitTable{
public:
  FitTable(const std::vector<Piece>&);
  bool operator()(Index ai, Position ap, Index bi, Position bp) const;
  Index GetSize() const {return static_cast<Index>(mTable[0].size());}

private:
  using Lookup = std::array<std::vector<bool>, 6>;
  using Table = std::array<std::vector<Lookup>, 6>;
  Table mTable;
};
