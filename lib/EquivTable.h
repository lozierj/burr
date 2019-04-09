#pragma once

#include <vector>

#include "Index.h"
#include "Piece.h"

class EquivTable{
public:
  EquivTable(const std::vector<Piece>&);
  Index operator()(Index) const;
  Index GetSize() const {return static_cast<Index>(mTable.size());}

private:
  std::vector<Index> mTable;
};
