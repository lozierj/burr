#include "Test.h"
#include "../lib/Piece.h"

void Test_Piece()
{
  int c{0};

  for (unsigned short n{0}; n < 1<<10; ++n)
  {
    Piece p(Piece::Notchable(n));
    if (p.IsConnected()) {
      ++c;
    }
  }

  test_equal(c, 147);
}
