struct Coordinates{
  using Type = signed char;

  Coordinates(Type xx, Type yy, Type zz) : x{xx}, y{yy}, z{zz} {}
  explicit Coordinates() : Coordinates(0, 0, 0) {}

  bool IsCube() const {return x & y & z & 1;}
  bool IsDelta() const {return !((x | y | z) & 1);}

  Type x;
  Type y;
  Type z;
};
