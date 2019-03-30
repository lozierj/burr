#pragma once

class Index{
public:
  using Type = unsigned char;

  Index(Type t) : mData{t} {}
  Index() : mData{0} {}

  constexpr operator const Type&() const {return mData;}
  constexpr operator Type&() {return mData;}

private:
  Type mData;
};
