#include <vector>

#include "Test.h"
#include "../lib/Notchables.h"
#include "../lib/TestReflect.h"

void Test_TestReflect()
{
  std::vector<Piece> n = Notchables();

  test_equal(TestReflect(n[  9], n[  9], Reflect(0u)), true);
  test_equal(TestReflect(n[  9], n[  9], Reflect(2u)), true);
  test_equal(TestReflect(n[  9], n[  9], Reflect(4u)), true);
  test_equal(TestReflect(n[  9], n[  9], Reflect(6u)), true);

  test_equal(TestReflect(n[113], n[113], Reflect(0u)), true);
  test_equal(TestReflect(n[113], n[113], Reflect(2u)), true);
  test_equal(TestReflect(n[113], n[113], Reflect(4u)), false);
  test_equal(TestReflect(n[113], n[127], Reflect(4u)), true);
  test_equal(TestReflect(n[113], n[113], Reflect(6u)), false);
  test_equal(TestReflect(n[113], n[127], Reflect(6u)), true);

  test_equal(TestReflect(n[105], n[105], Reflect(0u)), true);
  test_equal(TestReflect(n[105], n[105], Reflect(2u)), false);
  test_equal(TestReflect(n[105], n[ 57], Reflect(2u)), true);
  test_equal(TestReflect(n[105], n[105], Reflect(4u)), true);
  test_equal(TestReflect(n[105], n[105], Reflect(6u)), false);
  test_equal(TestReflect(n[105], n[ 57], Reflect(6u)), true);

  test_equal(TestReflect(n[ 60], n[ 60], Reflect(0u)), true);
  test_equal(TestReflect(n[ 60], n[ 60], Reflect(2u)), false);
  test_equal(TestReflect(n[ 60], n[108], Reflect(2u)), true);
  test_equal(TestReflect(n[ 60], n[ 60], Reflect(4u)), false);
  test_equal(TestReflect(n[ 60], n[ 51], Reflect(4u)), true);
  test_equal(TestReflect(n[ 60], n[ 60], Reflect(6u)), false);
  test_equal(TestReflect(n[ 60], n[ 99], Reflect(6u)), true);
}
