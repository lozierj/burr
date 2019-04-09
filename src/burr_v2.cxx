#include <iostream>

#include "../lib/Generator.h"
#include "../lib/Notchables.h"

int main()
{
  Generator g(Notchables32());
  g.Generate();
}
