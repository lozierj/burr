#include <iostream>

#include "../lib/Generator.h"
#include "../lib/Apart.h"
#include "../lib/Notchables.h"

int main()
{
  Apart a;

  Generator g(Notchables32(), a);
  g.Generate();
}
