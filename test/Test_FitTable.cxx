#include <vector>

#include "Test.h"
#include "../lib/FitTable.h"

void Test_FitTable()
{
  std::vector<Piece> notchables;

  for (unsigned short n{0}; n < 1<<10; ++n)
  {
    Piece p(Piece::Notchable(n));
    if (p.IsConnected()) {
      notchables.push_back(p);
    }
  }

  FitTable ft(notchables);

  test_equal(ft(  0, 0, 12, 1), true);
  test_equal(ft(140, 0,  4, 4), true);
  test_equal(ft(  4, 1, 40, 2), true);
  test_equal(ft(128, 1, 32, 5), true);
  test_equal(ft(  2, 2, 88, 0), true);
  test_equal(ft(116, 2, 80, 3), true);
  test_equal(ft(  6, 3,  1, 1), true);
  test_equal(ft( 96, 3,  0, 4), true);

  test_equal(ft(128, 4, 17, 2), false);
  test_equal(ft(134, 4, 65, 5), false);
  test_equal(ft( 20, 5,  2, 0), false);
  test_equal(ft( 68, 5,  2, 3), false);

  test_equal(ft(0, 0, 0, 3), true);
  test_equal(ft(0, 1, 0, 4), true);
  test_equal(ft(0, 2, 0, 5), true);
}
