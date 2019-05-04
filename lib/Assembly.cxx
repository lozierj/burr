#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <iomanip>

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

bool Assembly::Oriented(const ReflectTable& rt, bool proper) const
{
  for (Reflect::Type ref{0}; ref < 8; ++ref){
    for (Rotate::Type rot{0}; rot < 3; ++rot){
      if (!(Reflect(ref).IsProper()) && proper) continue;
      if (Orient(rt, {ref, rot}) < *this) return false;
    }
  }

  return true;
}

void Assembly::ToSetForm(const EquivTable& et)
{
  for (Index& i : mData) i = et(i);
  std::sort(mData.begin(), mData.end());
}

const Index& Assembly::operator[](Position p) const
{
  assert(p < 6);
  return mData[p];
}

Index& Assembly::operator[](Position p)
{
  assert(p < 6);
  return mData[p];
}

bool Assembly::operator<(const Assembly& comp) const
{
  for (unsigned i{0}; i < 6; ++i){
    if (mData[i] < comp.mData[i]) return true;
    if (mData[i] > comp.mData[i]) return false;
  }

  return false;
}

int Assembly::Holes(const std::vector<Piece>& vec) const
{
  int holes{-40};
  for (Index i : mData) holes += vec[i].Holes();
  return holes;
}

//----

bool Assembly::Fits(const FitTable& ft, Position p, Position q) const
{
  return ft(mData[p], p, mData[q], q);
}

Assembly Assembly::Orient(const ReflectTable& rt, PointGroup pg) const
{
  Assembly ret = *this;

  Reflect::Type ref{pg.GetReflect().GetRep()};
  Reflect yz(6);

  if (ref & 1u){
    ref ^= 3u;
    Index tempa{ret[0]}; ret[0] = ret[3]; ret[3] = tempa;
    Index tempb{ret[1]}; ret[1] = ret[4]; ret[4] = tempb;
    ret[1] = rt(ret[1], yz); ret[2] = rt(ret[2], yz);
    ret[4] = rt(ret[4], yz); ret[5] = rt(ret[5], yz);
  }

  if (ref & 2u){
    ref ^= 6u;
    Index tempa{ret[1]}; ret[1] = ret[4]; ret[4] = tempa;
    Index tempb{ret[2]}; ret[2] = ret[5]; ret[5] = tempb;
    ret[0] = rt(ret[0], yz); ret[2] = rt(ret[2], yz);
    ret[3] = rt(ret[3], yz); ret[5] = rt(ret[5], yz);
  }

  if (ref){
    assert(ref == 4u);

    Reflect y(2);
    Reflect z(4);

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

std::ostream& operator<<(std::ostream& os, const Assembly& a)
{
  for (Index i : a.mData){
    os << std::setw(4);
    os << static_cast<int>(i);
  }
  return os;
}
