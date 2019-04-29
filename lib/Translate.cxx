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

void Translate::operator+=(const Translate& rhs)
{
  mOffset.x += rhs.GetRep().x;
  mOffset.y += rhs.GetRep().y;
  mOffset.z += rhs.GetRep().z;
}

bool Translate::operator!=(const Translate& rhs) const
{
  return     mOffset.x != rhs.GetRep().x
         ||  mOffset.y != rhs.GetRep().y
         ||  mOffset.z != rhs.GetRep().z;
}

Translate Translate::operator-() const
{
  return {static_cast<Translate::Type>(-mOffset.x),
          static_cast<Translate::Type>(-mOffset.y),
          static_cast<Translate::Type>(-mOffset.z)};
}

//----

Translate operator-(const Translate& lhs, const Translate& rhs)
{
  return {static_cast<Translate::Type>(lhs.GetRep().x - rhs.GetRep().x),
          static_cast<Translate::Type>(lhs.GetRep().y - rhs.GetRep().y),
          static_cast<Translate::Type>(lhs.GetRep().z - rhs.GetRep().z)};
}

Translate::Type operator*(const Translate& lhs, const Translate& rhs)
{
  return static_cast<Translate::Type>(
      lhs.GetRep().x*rhs.GetRep().x +
      lhs.GetRep().y*rhs.GetRep().y +
      lhs.GetRep().z*rhs.GetRep().z);
}
