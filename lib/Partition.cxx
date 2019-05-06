#include "Partition.h"

bool Partition::IsIn(Position p) const
{
  return (1u << p) & mData;
}

bool Partition::ThreeAxes() const
{
  return ((mData & 07u) | ((mData & 070u) >> 3)) == 07u;
}

bool Partition::IsSubset(Partition super) const
{
  return !(~super.mData & mData);
}

Partition Partition::Complement(Partition super) const
{
  return super.mData & ~mData;
}

void Partition::RotateXZ()
{
  Type ret(mData & 022u);
  ret |= (mData & 05u) << 3;
  ret |= (mData & 050u) >> 3;
  mData = ret;
}
