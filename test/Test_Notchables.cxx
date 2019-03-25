#include "Test.h"
#include "../lib/Notchables.h"

void Test_Notchables()
{
  std::vector<Piece> n{Notchables()};
  test_equal(n.size(), 147u);

  std::vector<Piece> t{Notchables32()};
  test_equal(t.size(), 69u);
}
