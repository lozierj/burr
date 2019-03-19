#include <array>

#include "Coordinates.h"
#include "TestReflect.h"

bool TestReflect(Piece a, Piece b, Reflect r)
{
  Coordinates lower{0, -2, -6};
  Coordinates upper{4, 2, 6};

  for (Coordinates::Type x(lower.x + 1); x < upper.x; x += 2) {
    for (Coordinates::Type y(lower.y + 1); y < upper.y; y += 2) {
      for (Coordinates::Type z(lower.z + 1); z < upper.z; z += 2) {
        bool ao{a.IsOccupied({x, y, z})};
        bool bo{b.IsOccupied(r.Apply({x, y, z}))};
        if (ao != bo) return false;
      }
    }
  }

  return true;
}
