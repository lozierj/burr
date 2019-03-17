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

bool Assembly::Fits(const FitTable& ft, Position p, Position q) const
{
  return ft(mData[p], p, mData[q], q);
}
