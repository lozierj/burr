#include <array>
#include <stdexcept>

#include "Piece.h"

Piece Piece::Notchable(unsigned short notches)
{
  if (notches >= 1<<10) throw std::logic_error("too many notches");

  static std::array<Type, 10> notchMasks{
      0x00000202, 0x00000404, 0x00000808, 0x00001010,
      0x00040004, 0x00080008, 0x04000400, 0x08000800, 0x04040000, 0x08080000};

  Piece ret(0x3F3F3F3F);

  size_t i{0};
  while (notches) {
    if (notches & 1) ret.mData &= ~(notchMasks[i]);
    ++i;
    notches >>= 1;
  }

  return ret;
}

bool Piece::IsOccupied(Coordinates coord) const
{
  if (!coord.IsCube()) throw std::logic_error("coord not aligned");

  if (coord.x < -2 || coord.x > 2) throw std::logic_error("x out of bounds");
  if (coord.y <  0 || coord.y > 4) throw std::logic_error("y out of bounds");
  if (coord.z < -6 || coord.z > 6) throw std::logic_error("z out of bounds");

  int xBit{(coord.x + 1) << 2};
  int yBit{(coord.y - 1) << 3};
  int zBit{(coord.z + 5) >> 1};

  return mData & (1 << (xBit + yBit + zBit));
}

bool Piece::IsConnected() const
{
  for (Coordinates::Type z1{-5}; z1 < 4; z1 += 2) {
    bool conn{false};

    Coordinates::Type z2(z1 + 2);
    conn = conn || (IsOccupied({-1, 1, z1}) && IsOccupied({-1, 1, z2}));
    conn = conn || (IsOccupied({-1, 3, z1}) && IsOccupied({-1, 3, z2}));
    conn = conn || (IsOccupied({ 1, 1, z1}) && IsOccupied({ 1, 1, z2}));
    conn = conn || (IsOccupied({ 1, 3, z1}) && IsOccupied({ 1, 3, z2}));

    if (!conn) {
      return false;
    }
  }
  return true;
}
