#include <array>

#include "Coordinates.h"
#include "Piece.h"
#include "PointGroup.h"
#include "TestFit.h"

bool TestFit(Piece a, unsigned ap, Piece b, unsigned bp)
{
  if (ap >= 6 || bp >= 6) throw std::logic_error("bad position");

  static std::array<Coordinates, 6> lower{{
    { 0, -2, -6}, {-6,  0, -2}, {-2, -6,  0},
    {-4, -2, -6}, {-6, -4, -2}, {-2, -6, -4}
  }};

  static std::array<Coordinates, 6> upper{{
    { 4,  2,  6}, { 6,  4,  2}, { 2,  6,  4},
    { 0,  2,  6}, { 6,  0,  2}, { 2,  6,  0}
  }};

  static std::array<PointGroup, 6> transform{{
    {0u, 0u}, {0u, 1u}, {0u, 2u},
    {3u, 0u}, {3u, 1u}, {3u, 2u}
  }};

  const Coordinates::Type xi{std::max(lower[ap].x, lower[bp].x)};
  const Coordinates::Type yi{std::max(lower[ap].y, lower[bp].y)};
  const Coordinates::Type zi{std::max(lower[ap].z, lower[bp].z)};

  const Coordinates::Type xf{std::min(upper[ap].x, upper[bp].x)};
  const Coordinates::Type yf{std::min(upper[ap].y, upper[bp].y)};
  const Coordinates::Type zf{std::min(upper[ap].z, upper[bp].z)};

  for (Coordinates::Type x(xi + 1); x < xf; x += 2) {
    for (Coordinates::Type y(yi + 1); y < yf; y += 2) {
      for (Coordinates::Type z(zi + 1); z < zf; z += 2) {
        bool ao{a.IsOccupied(transform[ap].Invert({x, y, z}))};
        bool bo{b.IsOccupied(transform[bp].Invert({x, y, z}))};
        if (ao & bo) return false;
      }
    }
  }

  return true;
}
