#include <iostream>

#include "../lib/Generator.h"

int main()
{
  FitTable ft;
  ReflectTable rt;

  Generator g(ft, rt);
  g.Generate();
}
