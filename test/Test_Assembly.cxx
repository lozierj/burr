#include "Test.h"
#include "../lib/Assembly.h"
#include "../lib/FitTable.h"

void Test_Assembly()
{
  FitTable ft{};
  ReflectTable rt{};

  Assembly a({3, 12, 110, 56, 59, 107});
  test_equal(a.Oriented(rt), true);
  test_equal(a.Fits(ft, 4), true);
  test_equal(a.Fits(ft, 5), true);

  Assembly b({3, 107, 97, 109, 110, 12});
  test_equal(b.Oriented(rt), false);
  test_equal(b.Fits(ft, 4), true);
  test_equal(b.Fits(ft, 5), true);

  Assembly c({3, 12, 110, 56, 61, 109});
  test_equal(c.Oriented(rt), true);
  test_equal(c.Fits(ft, 1), true);
  test_equal(c.Fits(ft, 2), true);
  test_equal(c.Fits(ft, 4), false);
  test_equal(c.Fits(ft, 5), true);
}
