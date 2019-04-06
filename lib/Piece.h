#pragma once

#include <ostream>

#include "Coordinates.h"

class Piece{
public:
  static Piece Notchable(unsigned short notches);
  Piece(const Piece&) = default;
  Piece() : Piece(0) {};

  bool IsOccupied(Coordinates) const;
  bool IsConnected() const;

private:
  using Type = unsigned int;

  explicit Piece(Type data) : mData{data} {}

  Type mData;
};

std::ostream& operator<<(std::ostream&, const Piece&);
