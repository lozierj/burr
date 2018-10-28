#include <stdexcept>

#include "Rotate.h"

Rotate::Rotate(Rotate::Type v)
  : mValue{v}
{
  if (mValue != mValue % 3) throw std::logic_error("bad rotation magnitude");
}

Coordinates Rotate::Apply(const Coordinates& in) const
{
  switch (mValue){
    case 0: return in;
    case 1: return {in.z, in.x, in.y};
    case 2: return {in.y, in.z, in.x};
    default: throw std::logic_error("bad rotation magnitude");
  }
}
