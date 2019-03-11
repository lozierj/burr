#include <vector>

#include "Test.h"
#include "../lib/TestFit.h"

void Test_TestFit()
{
  std::vector<Piece> notchables;

  for (unsigned short n{0}; n < 1<<10; ++n)
  {
    Piece p(Piece::Notchable(n));
    if (p.IsConnected()) {
      notchables.push_back(p);
    }
  }

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
}
