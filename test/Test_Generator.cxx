#include "Test.h"
#include "../lib/Generator.h"

void Test_Generator()
{
  struct Counter{
    Counter() : tot{0u} {}
    void operator()(const Assembly&) {tot += 1u;}
    unsigned tot;
  };

  FitTable ft(Notchables32());
  ReflectTable rt(Notchables32());
  Counter c;

  Generator g(ft, rt, c);
  //g.Generate();

  test_equal(c.tot, 1'173'075u); //not verified
}
