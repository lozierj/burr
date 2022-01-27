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

  test_equal(z.ThreeAxes(), false);
  test_equal(h.ThreeAxes(), true);
  test_equal(i.ThreeAxes(), false);

  test_equal(i.IsIn(0), false);
  test_equal(i.IsIn(1), false);
  test_equal(i.IsIn(3), true);
  test_equal(i.IsIn(4), true);
  test_equal(i.IsIn(5), false);

  test_equal(z.IsSingle(), false);
  test_equal(h.IsSingle(), false);
  test_equal(i.IsSingle(), false);
  test_equal(Partition{040u}.IsSingle(), true);
  test_equal(Partition{01u}.IsSingle(), true);
  test_equal(Partition{30u}.IsSingle(), false);
  test_equal(Partition{13u}.IsSingle(), false);

  test_equal(z.First(), 0u);
  test_equal(h.First(), 2u);
  test_equal(i.First(), 4u);
  test_equal(Partition{0x4u}.First(), 2u);
  test_equal(Partition{0x5u}.First(), 2u);
}
