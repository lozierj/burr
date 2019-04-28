#include <cassert>

#include "OffsetTable.h"
#include "TestFit.h"

OffsetTable::OffsetTable(const std::vector<Piece>& vec, const ReflectTable& rt)
  : mRef{rt}
{
  unsigned n(vec.size());
  mPerp.reserve(n);
  mPara.reserve(n);

  for (Index ai{0}; ai < n; ++ai){
    mPerp.emplace_back();
    mPara.emplace_back();
    mPerp[ai].reserve(n);
    mPara[ai].reserve(n);

    for (Index bi{0}; bi < n; ++bi){
      mPerp[ai].emplace_back();
      mPara[ai].emplace_back();

      for (Translate::Type x{0}; x < 7; ++x){
        for (Translate::Type y{0}; y < 3; ++y){
          for (Translate::Type z{0}; z < 7; ++z){
            Translate::Type xc = 2*x - 4;
            Translate::Type yc = 2*y - 4;
            Translate::Type zc = 2*z - 6;
            (mPerp[ai][bi])[x][y][z] =
                TestFit(vec[ai], 0, vec[bi], 1, {xc, yc, zc});
          }
        }
      }

      for (Translate::Type x{0}; x < 3; ++x){
        for (Translate::Type y{0}; y < 3; ++y){
          for (Translate::Type z{0}; z < 11; ++z){
            Translate::Type xc = 2*x + 2;
            Translate::Type yc = 2*y - 2;
            Translate::Type zc = 2*z - 10;
            (mPara[ai][bi])[x][y][z] =
                TestFit(vec[ai], 0, vec[bi], 3, {xc, yc, zc});
          }
        }
      }

    }
  }

}

bool OffsetTable::Perp(Index ai, Index bi, Translate off, PointGroup pg) const
{
  Coordinates c = pg.Apply(off.GetRep());
  if (c.x < -4 || c.x > 8) return true;
  if (c.y < -4 || c.y > 0) return true;
  if (c.z < -6 || c.z > 6) return true;
  return (mPerp[ai][bi])[(c.x >> 1) + 2][(c.y >> 1) + 2][(c.z >> 1) + 3];
}

bool OffsetTable::Para(Index ai, Index bi, Translate off, Rotate r) const
{
  Coordinates c = r.Apply(off.GetRep());
  if (c.x <   2 || c.x >  6) return true;
  if (c.y <  -2 || c.y >  2) return true;
  if (c.z < -10 || c.z > 10) return true;
  return (mPara[ai][bi])[(c.x >> 1) - 1][(c.y >> 1) + 1][(c.z >> 1) + 5];
}

bool OffsetTable::operator()(
    Index ai, Position ap, Index bi, Position bp, Translate offset) const
{
  assert(ap < 6 && bp < 6);
  assert(ai < mPerp.size() && bi < mPerp[0].size());
  assert(offset.GetRep().IsDelta());

  if (ap > bp){
    std::swap(ap, bp);
    std::swap(ai, bi);
    offset = -offset;
  }

  static const Reflect I{0u};
  static const Reflect xy{3u};
  static const Reflect yz{6u};
  static const Reflect zx{5u};

  static const Rotate i{0u};
  static const Rotate r{2u};
  static const Rotate r2{1u};

  switch (ap){
    case 0:
      switch (bp){
        case 1: return Perp(     ai     ,      bi     ,  offset, {I, i});
        case 2: return Perp(     bi     ,      ai     , -offset, {I, r2});
        case 3: return Para(ai, bi, offset, i);
        case 4: return Perp(mRef(ai, yz),      bi     ,  offset, {yz, i});
        case 5: return Perp(mRef(bi, yz), mRef(ai, yz), -offset, {yz, r2});
        default: throw std::logic_error("bad offset pieces");
      }
    case 1:
      switch (bp){
        case 2: return Perp(     ai     ,      bi     ,  offset, {I, r});
        case 3: return Perp(mRef(bi, yz), mRef(ai, yz), -offset, {zx, i});
        case 4: return Para(ai, bi, offset, r);
        case 5: return Perp(mRef(ai, yz),      bi     ,  offset, {zx, r});
        default: throw std::logic_error("bad offset pieces");
      }
    case 2:
      switch (bp){
        case 3: return Perp(mRef(ai, yz),      bi     ,  offset, {xy, r2});
        case 4: return Perp(mRef(bi, yz), mRef(ai, yz), -offset, {xy, r});
        case 5: return Para(ai, bi, offset, r2);
        default: throw std::logic_error("bad offset pieces");
      }
    case 3:
      switch (bp){
        case 4: return Perp(     ai     , mRef(bi, yz),  offset, {xy, i});
        case 5: return Perp(     bi     , mRef(ai, yz), -offset, {zx, r2});
        default: throw std::logic_error("bad offset pieces");
      }
    case 4:
      switch (bp){
        case 5: return Perp(     ai     , mRef(bi, yz),  offset, {yz, r});
        default: throw std::logic_error("bad offset pieces");
      }
    default: throw std::logic_error("bad offset pieces");
  }
}
