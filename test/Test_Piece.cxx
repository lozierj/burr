#include "Test.h"
#include "../lib/Piece.h"

void Test_Piece()
{
  Piece y{Piece::Notchable(0x3F)};
  test_equal(y.IsOccupied({3, -1,  1}), false);
  test_equal(y.IsOccupied({3, -1, -1}), false);
  test_equal(y.IsOccupied({3,  1, -1}), true);
  test_equal(y.IsOccupied({3, -1,  5}), true);
  test_equal(y.IsConnected(), true);

  Piece broken{Piece::Notchable(0x104)};
  test_equal(broken.IsOccupied({3, -1,  1}), true);
  test_equal(broken.IsOccupied({3, -1, -1}), false);
  test_equal(broken.IsOccupied({3,  1, -1}), false);
  test_equal(broken.IsOccupied({3, -1,  5}), true);
  test_equal(broken.IsConnected(), false);
}
