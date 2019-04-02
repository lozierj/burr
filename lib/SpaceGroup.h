#pragma once

#include "Coordinates.h"
#include "PointGroup.h"
#include "Translate.h"

class SpaceGroup{
public:
  SpaceGroup(const PointGroup&, const Translate&);

  Coordinates Apply(const Coordinates& in) const;
  Coordinates Invert(const Coordinates& in) const;

private:
  PointGroup mPointGroup;
  Translate mTranslate;
};
