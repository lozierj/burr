#include <iostream>

#include "../lib/Generator.h"
#include "../lib/Notchables.h"

#include "../lib/Translate.h"
#include "../lib/TestFit.h"

int main()
{
  Generator g{Notchables32()};
  g.Generate();
}
