#include "../lib/Generator.h"
#include "../lib/Notchables.h"

int main()
{
  Generator g{Notchables()};
  g.Generate();
}
