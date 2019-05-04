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
  bool IsAmbiguous() const; //TODO: test
  bool IsSubset(const Piece&) const; //TODO: test
  bool operator==(const Piece&) const;

  Piece Twist() const;
  int Holes() const;

private:
  using Type = unsigned int;

  explicit Piece(Type data) : mData{data} {}

  Type mData;
};

std::ostream& operator<<(std::ostream&, const Piece&);
