#pragma once

#include <map>
#include <vector>

#include "Assembly.h"
#include "Apart.h"
#include "Piece.h"

class SolutionMap{
public:
  SolutionMap(const EquivTable& et, const OffsetTable& ot,
              const ReflectTable& rt)
    : mMap{}, mEquiv{et}, mOffset{ot}, mReflect{rt} {}

  void Add(const Assembly& a);
  void Print(const std::vector<Piece>&) const;

private:
  using Map = std::map<Assembly, Level>;
  Map mMap;
  const EquivTable& mEquiv;
  const OffsetTable& mOffset;
  const ReflectTable& mReflect;
};
