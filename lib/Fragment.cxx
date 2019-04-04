#include "Fragment.h"
#include "TestFit.h"

void Fragment::Shift(Partition p, Translate c)
{
  for (Position i{0}; i < 5; ++i){
    if (p.IsIn(i)) mDeltas[i] += c;
  }
}

bool Fragment::CheckFree(Partition, Translate) const
{
  return false; //TODO
}

bool Fragment::CheckFit(Partition p, const std::array<Piece, 6>& a) const
{
  for (Position i{0}; i < 5; ++i){
    if (p.IsIn(i)) continue;

    for (Position j{0}; j < 5; ++j){
      if (p.IsIn(j) &&
          !TestFit(a[i], i, a[j], j,
                   mDeltas[j] - mDeltas[i])){
        return false;
      }
    }
  }

  for (Position j{0}; j < 5; ++j){
    if (p.IsIn(j) &&
        !TestFit(a[5], 5, a[j], j,
                 mDeltas[j])){
      return false;
    }
  }

  return true;
}
