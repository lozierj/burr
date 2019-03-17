#include <array>
#include <vector>

#include "Piece.h"

class FitTable{
public:
  using Index = unsigned;
  FitTable(const std::vector<Piece>&);
  bool operator()(Index ai, unsigned ap, Index bi, unsigned bp) const;
  Index GetSize() const {return mTable[0].size();}

private:
  using Lookup = std::array<std::vector<bool>, 6>;
  using Table = std::array<std::vector<Lookup>, 6>;
  Table mTable;
};
