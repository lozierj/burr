#include <vector>

#include "Test.h"
#include "../lib/TestFit.h"
#include "../lib/Notchables.h"
#include "../lib/Piece.h"

void Test_TestFit()
{
  std::vector<Piece> notchables{Notchables()};

  test_equal(TestFit(notchables[  0], 0, notchables[12], 1), true);
  test_equal(TestFit(notchables[140], 0, notchables[ 4], 4), true);
  test_equal(TestFit(notchables[  4], 1, notchables[40], 2), true);
  test_equal(TestFit(notchables[128], 1, notchables[32], 5), true);
  test_equal(TestFit(notchables[  2], 2, notchables[88], 0), true);
  test_equal(TestFit(notchables[116], 2, notchables[80], 3), true);
  test_equal(TestFit(notchables[  6], 3, notchables[ 1], 1), true);
  test_equal(TestFit(notchables[ 96], 3, notchables[ 0], 4), true);

  test_equal(TestFit(notchables[128], 4, notchables[17], 2), false);
  test_equal(TestFit(notchables[134], 4, notchables[65], 5), false);
  test_equal(TestFit(notchables[ 20], 5, notchables[ 2], 0), false);
  test_equal(TestFit(notchables[ 68], 5, notchables[ 2], 3), false);

  test_equal(TestFit(notchables[0], 0, notchables[0], 3), true);
  test_equal(TestFit(notchables[0], 1, notchables[0], 4), true);
  test_equal(TestFit(notchables[0], 2, notchables[0], 5), true);

  Piece x{Piece::Notchable(0x8b)};
  Piece y{Piece::Notchable(0x1f)};
  Piece z{Piece::Notchable( 0xf)};
  Piece u{Piece::Notchable(0xcb)};
  Piece v{Piece::Notchable( 0xf)};
  Piece w{Piece::Notchable(0x89)};

  test_equal(TestFit(y, 1, u, 3, {0,  2, 0}), false);
  test_equal(TestFit(y, 1, u, 3, {0, -2, 0}), true);
  test_equal(TestFit(z, 2, u, 3, {0, -2, 0}), true);
  test_equal(TestFit(v, 4, u, 3, {0, -2, 0}), true);
  test_equal(TestFit(w, 5, u, 3, {0, -2, 0}), true);

  test_equal(TestFit(u, 3, y, 1, {2,  0, 0}), false);
  test_equal(TestFit(u, 3, y, 1, {2,  2, 0}), true);
  test_equal(TestFit(w, 5, y, 1, {4,  0, 0}), true);
  test_equal(TestFit(w, 5, y, 1, {6,  0, 0}), false);
}
