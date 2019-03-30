#pragma once

class Position{
public:
  using Type = unsigned;
  Position(Type t) : mData{t} {}

  constexpr operator const Type&() const {return mData;}
  constexpr operator Type&() {return mData;}

private:
  Type mData;
};
