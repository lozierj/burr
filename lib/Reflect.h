#pragma once

#include "Coordinates.h"

class Reflect{
public:
  using Type = unsigned char;

  explicit Reflect(Type);

  bool IsProper() const {return 1u << mValue & 0x69;}

  Coordinates Apply(const Coordinates&) const;
  Coordinates Invert(const Coordinates& in) const {return Apply(in);}

private:
  Type mValue;
};
