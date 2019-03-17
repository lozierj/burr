#include <iostream>

#include "../lib/Generator.h"

int main()
{
  FitTable ft;

  Generator g(ft);
  g.Generate();
}
