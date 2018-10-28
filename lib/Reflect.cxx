#include <stdexcept>

#include "Reflect.h"

Reflect::Reflect(Reflect::Type v)
  : mValue{v}
{
  if (!(1u << mValue & 0xFF)) throw std::logic_error("bad reflection");
}

Coordinates Reflect::Apply(const Coordinates& in) const
{
  return {mValue & 1u ? static_cast<Coordinates::Type>(-in.x) : in.x,
          mValue & 2u ? static_cast<Coordinates::Type>(-in.y) : in.y,
          mValue & 4u ? static_cast<Coordinates::Type>(-in.z) : in.z};
}
