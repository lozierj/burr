#include "Test.h"
#include "../lib/Coordinates.h"

void Test_Coordinates()
{
  Coordinates z;
  test_equal(z.IsCube(), false);
  test_equal(z.IsDelta(), true);
  test_equal(z.x, 0);
  test_equal(z == z, true);

  Coordinates d{1, 3, -5};
  test_equal(d.IsCube(), true);
  test_equal(d.IsDelta(), false);
  test_equal(d.y, 3);
  test_equal(d == z, false);

  Coordinates b{-2, 7, -4};
  test_equal(b.IsCube(), false);
  test_equal(b.IsDelta(), false);
  test_equal(b.z, -4);
  test_equal(b != b, false);
  test_equal(b != d, true);
}
