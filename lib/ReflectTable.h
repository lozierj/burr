#pragma once

#include <array>
#include <vector>

#include "Index.h"
#include "Piece.h"
#include "Reflect.h"
#include "Notchables.h"

class ReflectTable{
public:
  ReflectTable(const std::vector<Piece>& = Notchables());
  Index operator()(Index, Reflect) const;
  Index GetSize() const {return static_cast<Index>(mTable[0].size());}

private:
  std::array<std::vector<Index>, 8> mTable;
};
