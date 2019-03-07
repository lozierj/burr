#pragma once

#include "Coordinates.h"

class Rotate{
public:
  using Type = unsigned char;

  explicit Rotate(Type);

  Coordinates Apply(const Coordinates&) const;
  Coordinates Invert(const Coordinates&) const;

private:
  Type mValue;
};
