#include "Coordinates.h"

bool Coordinates::operator==(const Coordinates& rhs) const
{
  return x == rhs.x && y == rhs.y && z == rhs.z;
}

std::ostream& operator<<(std::ostream& os, const Coordinates& c)
{
  os << "(" << +c.x << ", " << +c.y << ", " << +c.z << ")";
  return os;
}
