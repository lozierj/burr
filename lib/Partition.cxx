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

bool Partition::IsSingle() const
{
  if (!mData) return false;
  return !(mData & (mData - 1u));
}

Partition Partition::Complement(Partition super) const
{
  return super.mData & ~mData;
}

unsigned Partition::First() const
{
  Partition::Type test{mData};
  unsigned ret{0u};

  while(test > 1){
    ++ret;
    test >>= 1;
  }

  return ret;
}

void Partition::RotateXZ()
{
  Type ret(mData & 022u);
  ret |= (mData & 05u) << 3;
  ret |= (mData & 050u) >> 3;
  mData = ret;
}
