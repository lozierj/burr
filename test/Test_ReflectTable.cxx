#include <vector>

#include "Test.h"
#include "../lib/ReflectTable.h"
#include "../lib/Notchables.h"

void Test_ReflectTable()
{
  ReflectTable rt{Notchables()};

  test_equal(rt.GetSize(), 147);

  test_equal(rt(  9, Reflect(0u)),   9);
  test_equal(rt(  9, Reflect(2u)),   9);
  test_equal(rt(  9, Reflect(4u)),   9);
  test_equal(rt(  9, Reflect(6u)),   9);

  test_equal(rt(113, Reflect(0u)), 113);
  test_equal(rt(113, Reflect(2u)), 113);
  test_equal(rt(113, Reflect(4u)), 127);
  test_equal(rt(113, Reflect(6u)), 127);

  test_equal(rt(105, Reflect(0u)), 105);
  test_equal(rt(105, Reflect(2u)),  57);
  test_equal(rt(105, Reflect(4u)), 105);
  test_equal(rt(105, Reflect(6u)),  57);

  test_equal(rt( 60, Reflect(0u)),  60);
  test_equal(rt( 60, Reflect(2u)), 108);
  test_equal(rt( 60, Reflect(4u)),  51);
  test_equal(rt( 60, Reflect(6u)),  99);
}
