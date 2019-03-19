#include <stdexcept>

#include "Assembly.h"

bool Assembly::Fits(const FitTable& ft, Position p) const
{
  switch (static_cast<Position::Type>(p)) {
    case 0: return true;
    case 1: return Fits(ft, 0, 1);
    case 2: return Fits(ft, 0, 2) && Fits(ft, 1, 2);
    case 3: return Fits(ft, 1, 3) && Fits(ft, 2, 3);
    case 4: return Fits(ft, 0, 4) && Fits(ft, 2, 4)
                && Fits(ft, 3, 4);
    case 5: return Fits(ft, 0, 5) && Fits(ft, 1, 5)
                && Fits(ft, 3, 5) && Fits(ft, 4, 5);
    default: throw std::logic_error("bad piece");
  }
}

bool Assembly::Oriented(const ReflectTable& rt) const
{
  for (Reflect::Type ref{0}; ref < 8; ++ref){
    for (Rotate::Type rot{0}; rot < 3; ++rot){
      if (IsBefore(Orient(rt, {ref, rot}))) return false;
    }
  }

  return true;
}


bool Assembly::Fits(const FitTable& ft, Position p, Position q) const
{
  return ft(mData[p], p, mData[q], q);
}

Assembly Assembly::Orient(const ReflectTable& rt, PointGroup pg) const
{
  Assembly ret = *this;

  Reflect::Type ref{pg.GetReflect().GetRep()};
  Reflect y(2);
  Reflect z(4);

  if (ref & 1u){
    Index temp{ret[0]}; ret[0] = ret[3]; ret[3] = temp;
    ret[0] = rt(ret[0], y); ret[1] = rt(ret[1], z); ret[2] = rt(ret[2], y);
    ret[3] = rt(ret[3], y); ret[4] = rt(ret[4], z); ret[5] = rt(ret[5], y);
  }

  if (ref & 2u){
    Index temp{ret[1]}; ret[1] = ret[4]; ret[4] = temp;
    ret[0] = rt(ret[0], y); ret[1] = rt(ret[1], y); ret[2] = rt(ret[2], z);
    ret[3] = rt(ret[3], y); ret[4] = rt(ret[4], y); ret[5] = rt(ret[5], z);
  }

  if (ref & 4u){
    Index temp{ret[2]}; ret[2] = ret[5]; ret[5] = temp;
    ret[0] = rt(ret[0], z); ret[1] = rt(ret[1], y); ret[2] = rt(ret[2], y);
    ret[3] = rt(ret[3], z); ret[4] = rt(ret[4], y); ret[5] = rt(ret[5], y);
  }

  Rotate::Type rot{pg.GetRotate().GetRep()};

  if (rot == 1u){
    Index tempp{ret[0]}; ret[0] = ret[1]; ret[1] = ret[2]; ret[2] = tempp;
    Index tempn{ret[3]}; ret[3] = ret[4]; ret[4] = ret[5]; ret[5] = tempn;
  } else if (rot == 2u){
    Index tempp{ret[0]}; ret[0] = ret[2]; ret[2] = ret[1]; ret[1] = tempp;
    Index tempn{ret[3]}; ret[3] = ret[5]; ret[5] = ret[4]; ret[4] = tempn;
  }

  return ret;
}

bool Assembly::IsBefore(const Assembly& comp) const
{
  for (unsigned i{0}; i < 6; ++i){
    if (comp.mData[i] < mData[i]) return true;
    if (comp.mData[i] > mData[i]) return false;
  }

  return false;
}
