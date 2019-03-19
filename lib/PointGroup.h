#pragma once

#include "Coordinates.h"
#include "Reflect.h"
#include "Rotate.h"

class PointGroup{
public:
  PointGroup(const Reflect& ref, const Rotate& rot);
  PointGroup(Reflect::Type, Rotate::Type);

  bool IsProper() const {return mReflect.IsProper();}

  Coordinates Apply(const Coordinates& in) const;
  Coordinates Invert(const Coordinates& in) const;

  Reflect GetReflect() const {return mReflect;}
  Rotate GetRotate() const {return mRotate;}

private:
  Reflect mReflect;
  Rotate mRotate;
};
