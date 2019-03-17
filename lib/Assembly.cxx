#include <stdexcept>

#include "Assembly.h"

bool Assembly::Fits(Position p) const
{
  switch (static_cast<Position::Type>(p)) {
    case 0: return true;
    case 1: return Fits(0, 1);
    case 2: return Fits(0, 2) && Fits(1, 2);
    case 3: return Fits(1, 3) && Fits(2, 3);
    case 4: return Fits(0, 4) && Fits(2, 4) && Fits(3, 4);
    case 5: return Fits(0, 5) && Fits(1, 5) && Fits(3, 5) && Fits(4, 5);
    default: throw std::logic_error("bad piece");
  }
}

bool Assembly::Fits(Position p, Position q) const
{
  return cFitTable(mData[p], p, mData[q], q);
}
