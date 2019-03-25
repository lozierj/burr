#include <iostream>

#include "../lib/Generator.h"

int main()
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
  g.Generate();

  std::cout << c.tot << std::endl;
}
