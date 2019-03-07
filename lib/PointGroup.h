#pragma once

#include "Coordinates.h"
#include "Reflect.h"
#include "Rotate.h"

class PointGroup{
public:
  PointGroup(const Reflect& ref, const Rotate& rot);

  bool IsProper() const {return mReflect.IsProper();}

  Coordinates Apply(const Coordinates& in) const;
  Coordinates Invert(const Coordinates& in) const;

private:
  Reflect mReflect;
  Rotate mRotate;
};
