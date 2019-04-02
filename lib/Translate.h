#pragma once

#include "Coordinates.h"

class Translate{
public:
  using Type = Coordinates::Type;

  explicit Translate(Coordinates o) : mOffset{o} {}
  Translate(Type x, Type y, Type z) : mOffset{x, y, z} {}

  Coordinates GetRep() const {return mOffset;}

  Coordinates Apply(const Coordinates&) const;
  Coordinates Invert(const Coordinates&) const;

private:
  Coordinates mOffset;
};
