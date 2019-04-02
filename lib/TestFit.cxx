#include <array>
#include <stdexcept>

#include "Coordinates.h"
#include "Piece.h"
#include "PointGroup.h"
#include "SpaceGroup.h"
#include "TestFit.h"

bool TestFit(Piece a, Position ap, Piece b, Position bp, Translate offset)
{
  if (ap >= 6 || bp >= 6) throw std::logic_error("bad position");

  static std::array<Coordinates, 6> lower{{
    { 0, -2, -6}, {-6,  0, -2}, {-2, -6,  0},
    {-4, -2, -6}, {-6, -4, -2}, {-2, -6, -4}}};

  static std::array<Coordinates, 6> upper{{
    { 4,  2,  6}, { 6,  4,  2}, { 2,  6,  4},
    { 0,  2,  6}, { 6,  0,  2}, { 2,  6,  0}}};

  static std::array<PointGroup, 6> transform{{
    {0u, 0u}, {0u, 1u}, {0u, 2u},
    {3u, 0u}, {3u, 1u}, {3u, 2u}}};

  const Coordinates beg{Coordinates::max(lower[ap], offset.Apply(lower[bp]))};
  const Coordinates end{Coordinates::min(upper[ap], offset.Apply(upper[bp]))};

  const PointGroup at{transform[ap]};
  const SpaceGroup bt{transform[bp], offset};

  for (Coordinates::Type x(beg.x + 1); x < end.x; x += 2) {
    for (Coordinates::Type y(beg.y + 1); y < end.y; y += 2) {
      for (Coordinates::Type z(beg.z + 1); z < end.z; z += 2) {
        bool ao{a.IsOccupied(at.Invert({x, y, z}))};
        bool bo{b.IsOccupied(bt.Invert({x, y, z}))};
        if (ao && bo) return false;
      }
    }
  }

  return true;
}
