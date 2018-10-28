#pragma once

#include "Coordinates.h"

class Reflect{
public:
  using Type = unsigned char;

  explicit Reflect(Type);

  bool IsProper() const {return 1u << mValue & 0x69;}

  Coordinates Apply(const Coordinates&) const;

private:
  Type mValue;
};
