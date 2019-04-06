#include "Test.h"
#include "../lib/Apart.h"

void Test_Apart()
{
  std::array<Piece, 6> p{
    Piece::Notchable(0xCFu),
    Piece::Notchable(0x87u),
    Piece::Notchable(0x48u),
    Piece::Notchable(0x3Du),
    Piece::Notchable(0xC9u),
    Piece::Notchable(0x49u)};

  Apart a;

  a(p);
  //test_equal(a(p), 5);
}
