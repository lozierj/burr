#pragma once

#include "Apart.h"
#include "OffsetTable.h"
#include "ReflectTable.h"

struct SubLevel{
  Level mLevel;
  Level mSubLevel;
};

std::ostream& operator<<(std::ostream&, const SubLevel&);

SubLevel SubApart(Assembly, const OffsetTable&, const ReflectTable&);

