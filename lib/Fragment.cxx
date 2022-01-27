#include "Fragment.h"
#include "TestFit.h"

void Fragment::Shift(Partition p, Translate c)
{
  for (Position i{0}; i < 6; ++i){
    if (p.IsIn(i)) mDeltas[i] += c;
  }
}

bool Fragment::CheckFree(Partition move, Partition stat, Translate t) const
{
  static Piece key{Piece::Notchable(0x0u)};

  for (Position i{0}; i < 6; ++i){
    if (!stat.IsIn(i)) continue;

    for (Position j{0}; j < 6; ++j){
      if (move.IsIn(j)){
        if (!TestFit(key, i, key, j, mDeltas[j] - mDeltas[i])) return false;
        if (mDeltas[j]*t - mDeltas[i]*t <= 0) return false;
      }
    }
  }

  return true;
}

bool Fragment::CheckFree(Partition move, Translate t) const
{
  Partition stat{move.Complement(Partition::All())};
  return CheckFree(move, stat, t);
}

bool Fragment::CheckFit(Partition move, Partition stat,
                        Assembly a, const OffsetTable& ot) const
{
  for (Position i{0}; i < 6; ++i){
    if (!stat.IsIn(i)) continue;

    for (Position j{0}; j < 6; ++j){
      if (    move.IsIn(j)
           && !ot(a[i], i, a[j], j, mDeltas[j] - mDeltas[i])){
        return false;
      }
    }
  }

  return true;
}

bool Fragment::CheckFit(Partition move, Assembly a,
                        const OffsetTable& ot) const
{
  Partition stat{move.Complement(Partition::All())};
  return CheckFit(move, stat, a, ot);
}

bool Fragment::operator==(const Fragment& rhs) const
{
  for (Position i{0}; i < 6; ++i){
    if (mDeltas[i] != rhs.mDeltas[i]) return false;
  }

  return true;
}

std::ostream& operator<<(std::ostream& os, const Fragment& f)
{
  for (unsigned i{0}; i < 4; ++i){
    os << f.mDeltas[i] << ", ";
  }
  os << f.mDeltas[4];
  return os;
}
