#pragma once

#include <array>

#include "Index.h"
#include "FitTable.h"
#include "ReflectTable.h"
#include "EquivTable.h"
#include "PointGroup.h"
#include "Position.h"

class Assembly{
public:
  Assembly() : mData{0, 0, 0, 0, 0, 0} {}
  Assembly(std::array<Index, 6> l) : mData{l} {}

  bool Fits(const FitTable&, Position) const;
  bool Oriented(const ReflectTable&, bool proper = true) const;

  void ToSetForm(const EquivTable&);

  const Index& operator[](Position p) const;
  Index& operator[](Position p);

  bool operator<(const Assembly&) const;

  int Holes(const std::vector<Piece>&) const;

  friend std::ostream& operator<<(std::ostream&, const Assembly&);

private:
  bool Fits(const FitTable&, Position, Position) const;
  Assembly Orient(const ReflectTable&, PointGroup) const;

  std::array<Index, 6> mData;
};

std::ostream& operator<<(std::ostream&, const Assembly&);
