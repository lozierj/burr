#include <iostream>

#include "../lib/Generator.h"
#include "../lib/Piece.h"

int main()
{
  std::vector<Piece> v;

  v.push_back(Piece::Notchable(0x16u)); // M3
  v.push_back(Piece::Notchable(0x86u));

  //v.push_back(Piece::Notchable(0x26u)); // N3
  //v.push_back(Piece::Notchable(0x46u));

  v.push_back(Piece::Notchable(0x3Du)); // W
  v.push_back(Piece::Notchable(0xCBu));

  v.push_back(Piece::Notchable(0x3Bu)); // X
  v.push_back(Piece::Notchable(0xCDu));

  v.push_back(Piece::Notchable(0x3Fu)); // Y
  v.push_back(Piece::Notchable(0xCFu));

  //v.push_back(Piece::Notchable(0x2Fu)); // 4
  //v.push_back(Piece::Notchable(0x4Fu));

  //v.push_back(Piece::Notchable(0x1Fu)); // 19
  //v.push_back(Piece::Notchable(0x8Fu));


  Generator g(v);
  g.Generate();
}
