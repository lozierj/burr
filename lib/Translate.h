#pragma once

#include <iostream>

#include "Coordinates.h"

class Translate{
public:
  using Type = Coordinates::Type;

  explicit Translate(Coordinates o) : mOffset{o} {}
  Translate(Type x, Type y, Type z) : mOffset{x, y, z} {}
  Translate() = default;

  Coordinates GetRep() const {return mOffset;}

  Coordinates Apply(const Coordinates&) const;
  Coordinates Invert(const Coordinates&) const;

  void operator+=(const Translate&);
  bool operator!=(const Translate&) const;
  Translate operator-() const;

  friend std::ostream& operator<<(std::ostream&, const Translate&);

private:
  Coordinates mOffset;
};

Translate operator-(const Translate&, const Translate&);
Translate::Type operator*(const Translate&, const Translate&);

std::ostream& operator<<(std::ostream&, const Translate&);
