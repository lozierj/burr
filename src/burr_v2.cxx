#include <iostream>

#include "../lib/Generator.h"

int main()
{
  //for (auto p : Notchables32()) std::cout << p << std::endl;

  FitTable ft(Notchables32());
  ReflectTable rt(Notchables32());

  Generator g(ft, rt);
  g.Generate();
}
