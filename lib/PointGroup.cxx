#include "PointGroup.h"

PointGroup::PointGroup(const Reflect& ref, const Rotate& rot)
  : mReflect{ref}, mRotate{rot} {}

Coordinates PointGroup::Apply(const Coordinates& in) const
{
  return mRotate.Apply(mReflect.Apply(in));
}
