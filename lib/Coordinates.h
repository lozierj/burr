#pragma once

#include <ostream>

class Coordinates{
public:
  using Type = signed char;

  Coordinates(Type xx, Type yy, Type zz) : x{xx}, y{yy}, z{zz} {}
  explicit Coordinates() : Coordinates(0, 0, 0) {}

  bool IsCube() const {return x & y & z & 1;}
  bool IsDelta() const {return !((x | y | z) & 1);}

  bool operator==(const Coordinates&) const;
  bool operator!=(const Coordinates& rhs) const {return !(*this == rhs);}

  static Coordinates max(const Coordinates&, const Coordinates&);
  static Coordinates min(const Coordinates&, const Coordinates&);

  friend std::ostream& operator<<(std::ostream&, const Coordinates&);


  Type x;
  Type y;
  Type z;
};

std::ostream& operator<<(std::ostream&, const Coordinates&);
