#include "Coordinates.h"

bool Coordinates::operator==(const Coordinates& rhs) const
{
  return x == rhs.x && y == rhs.y && z == rhs.z;
}

Coordinates Coordinates::max(const Coordinates& l, const Coordinates& r)
{
  return {std::max(l.x, r.x), std::max(l.y, r.y), std::max(l.z, r.z)};
}

Coordinates Coordinates::min(const Coordinates& l, const Coordinates& r)
{
  return {std::min(l.x, r.x), std::min(l.y, r.y), std::min(l.z, r.z)};
}

std::ostream& operator<<(std::ostream& os, const Coordinates& c)
{
  os << "(" << +c.x << ", " << +c.y << ", " << +c.z << ")";
  return os;
}
