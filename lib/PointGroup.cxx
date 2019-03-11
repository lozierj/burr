#include "PointGroup.h"

PointGroup::PointGroup(const Reflect& ref, const Rotate& rot)
  : mReflect{ref}, mRotate{rot} {}

PointGroup::PointGroup(Reflect::Type ref, Rotate::Type rot)
  : mReflect{Reflect(ref)}, mRotate{Rotate(rot)} {}

Coordinates PointGroup::Apply(const Coordinates& in) const
{
  return mRotate.Apply(mReflect.Apply(in));
}

Coordinates PointGroup::Invert(const Coordinates& in) const
{
  return mReflect.Invert(mRotate.Invert(in));
}
