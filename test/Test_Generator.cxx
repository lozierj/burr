#include "Test.h"
#include "../lib/Generator.h"
#include "../lib/Notchables.h"

void Test_Generator()
{
  struct Counter{
    Counter() : tot{0u} {}
    void operator()(std::array<Piece, 6>) {tot += 1u;}
    unsigned tot;
  };

  Counter c;

  //Generator g(Notchables32(), c);
  //g.Generate();

  //test_equal(c.tot, 1'173'075u); //not verified
}
