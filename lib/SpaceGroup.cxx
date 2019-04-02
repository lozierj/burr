#include "SpaceGroup.h"

SpaceGroup::SpaceGroup(const PointGroup& pg, const Translate& trans)
  : mPointGroup{pg}, mTranslate{trans} {}

Coordinates SpaceGroup::Apply(const Coordinates& in) const
{
  return mTranslate.Apply(mPointGroup.Apply(in));
}

Coordinates SpaceGroup::Invert(const Coordinates& in) const
{
  return mPointGroup.Invert(mTranslate.Invert(in));
}
