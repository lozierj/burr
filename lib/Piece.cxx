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

  if (coord.x <  0 || coord.x > 4) throw std::logic_error("x out of bounds");
  if (coord.y < -2 || coord.y > 2) throw std::logic_error("y out of bounds");
  if (coord.z < -6 || coord.z > 6) throw std::logic_error("z out of bounds");

  int xBit{(coord.x - 1) << 3};
  int yBit{(coord.y + 1) << 2};
  int zBit{(coord.z + 5) >> 1};
  Type bit{1u << (xBit + yBit + zBit)};

  if (!(0x3F3F3F3F & bit)) throw std::logic_error("bit out of bounds");

  return mData & bit;
}

bool Piece::IsConnected() const
{
  for (Coordinates::Type z1{-5}; z1 < 4; z1 += 2) {
    bool conn{false};

    Coordinates::Type z2(z1 + 2);
    conn = conn || (IsOccupied({1, -1, z1}) && IsOccupied({1, -1, z2}));
    conn = conn || (IsOccupied({3, -1, z1}) && IsOccupied({3, -1, z2}));
    conn = conn || (IsOccupied({1,  1, z1}) && IsOccupied({1,  1, z2}));
    conn = conn || (IsOccupied({3,  1, z1}) && IsOccupied({3,  1, z2}));

    if (!conn) {
      return false;
    }
  }
  return true;
}

bool Piece::IsAmbiguous() const
{
  return IsOccupied({1, -1, -3}) && IsOccupied({1, 1, -3})
      && IsOccupied({1, -1,  3}) && IsOccupied({1, 1,  3});
}

bool Piece::IsSubset(const Piece& rhs) const
{
  return (!(~(rhs.mData) & mData));
}

std::ostream& operator<<(std::ostream& os, const Piece& p)
{
  for (Coordinates::Type z{-5}; z < 6; z += 2) {
    int plane{
        p.IsOccupied({1, -1, z})     +
        p.IsOccupied({1,  1, z}) * 2 +
        p.IsOccupied({3, -1, z}) * 4 +
        p.IsOccupied({3,  1, z}) * 8
    };

    switch (plane) {
      case  0: os << "0"; break;
      case  1: os << "T"; break;
      case  2: os << "L"; break;
      case  3: os << ":"; break;
      case  4: os << "M"; break;
      case  5: os << "^"; break;
      case  6: os << "?"; break;
      case  7: os << "?"; break;
      case  8: os << "W"; break;
      case  9: os << "?"; break;
      case 10: os << "V"; break;
      case 11: os << "?"; break;
      case 12: os << "|"; break;
      case 13: os << "?"; break;
      case 14: os << "?"; break;
      case 15: os << "-"; break;
      default: throw std::logic_error("bad plane config");
    }
  }

  return os;
}

