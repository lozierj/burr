#include "Test.h"
#include "../lib/Partition.h"

void Test_Partition()
{
  Partition z(0x0u); //------
  Partition h(0x7u); //xxx---
  Partition i(0x18u);//---xx-

  test_equal(z.IsIn(0), false);
  test_equal(z.IsIn(2), false);
  test_equal(z.IsIn(5), false);

  test_equal(h.IsIn(0), true);
  test_equal(h.IsIn(1), true);
  test_equal(h.IsIn(2), true);
  test_equal(h.IsIn(3), false);
  test_equal(h.IsIn(5), false);

  test_equal(i.IsIn(0), false);
  test_equal(i.IsIn(1), false);
  test_equal(i.IsIn(3), true);
  test_equal(i.IsIn(4), true);
  test_equal(i.IsIn(5), false);
}
