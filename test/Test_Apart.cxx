#include <fstream>

#include "Test.h"
#include "../lib/Apart.h"

void Test_Apart()
{
  std::ifstream s("data/ip2.tsv");
  s >> std::hex;

  using Pieces = std::array<Piece, 6>;

  for(int line{1}; line <= 164; ++line){
   Pieces v;

    for (unsigned i{0}; i < 6; ++i){
      unsigned short n;
      s >> n;
      v[i] = Piece::Notchable(n);
    }

    test_equal(Apart(v), 5);
  }

  std::array<Piece, 6> p{
    Piece::Notchable(0xCFu),
    Piece::Notchable(0x87u),
    Piece::Notchable(0x4bu),
    Piece::Notchable(0x3Du),
    Piece::Notchable(0xC9u),
    Piece::Notchable(0x49u)};

  test_equal(Apart(p), 5);
}
