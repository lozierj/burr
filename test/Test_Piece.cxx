#include <iostream>

#include "Test.h"
#include "../lib/Piece.h"

void Test_Piece()
{
  Piece t(3);
  test_equal(t.foo, 3);
}
