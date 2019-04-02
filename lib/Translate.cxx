#include "Translate.h"

Coordinates Translate::Apply(const Coordinates& in) const
{
  return {
      static_cast<Coordinates::Type>(in.x + mOffset.x),
      static_cast<Coordinates::Type>(in.y + mOffset.y),
      static_cast<Coordinates::Type>(in.z + mOffset.z)};
}

Coordinates Translate::Invert(const Coordinates& in) const
{
  return {
      static_cast<Coordinates::Type>(in.x - mOffset.x),
      static_cast<Coordinates::Type>(in.y - mOffset.y),
      static_cast<Coordinates::Type>(in.z - mOffset.z)};
}
