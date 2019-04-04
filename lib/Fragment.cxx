#include "Fragment.h"
#include "TestFit.h"

void Fragment::Shift(Partition p, Translate c)
{
  for (Position i{0}; i < 5; ++i){
    if (p.IsIn(i)) mDeltas[i] += c;
  }
}

bool Fragment::CheckFree(Partition p, Translate t) const
{
  static Piece key{Piece::Notchable(0x0u)};

  for (Position i{0}; i < 5; ++i){
    if (p.IsIn(i)) continue;

    for (Position j{0}; j < 5; ++j){
      if (p.IsIn(j)){
        if (!TestFit(key, i, key, j, mDeltas[j] - mDeltas[i])) return false;
        if (mDeltas[j]*t - mDeltas[i]*t <= 0) return false;
      }
    }
  }

  for (Position j{0}; j < 5; ++j){
    if (p.IsIn(j)){
      if (!TestFit(key, 5, key, j, mDeltas[j])) return false;
      if (mDeltas[j]*t <= 0) return false;
    }
  }

  return true;
}

bool Fragment::CheckFit(Partition p, const std::array<Piece, 6>& a) const
{
  for (Position i{0}; i < 5; ++i){
    if (p.IsIn(i)) continue;

    for (Position j{0}; j < 5; ++j){
      if (    p.IsIn(j)
           && !TestFit(a[i], i, a[j], j, mDeltas[j] - mDeltas[i])){
        return false;
      }
    }
  }

  for (Position j{0}; j < 5; ++j){
    if (    p.IsIn(j)
         && !TestFit(a[5], 5, a[j], j, mDeltas[j])){
      return false;
    }
  }

  return true;
}
