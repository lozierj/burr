#include <iostream>

#include "../lib/Assemblies.h"

int main()
{
  std::vector<Piece> notchables;

  for (unsigned short n{0}; n < 1<<10; ++n) {
  //for (unsigned short n :
  //    {0x188, 0x211, 0x3e, 0xc7, 0x3f, 0xcf, 0x1d, 0x8b, 0x2f, 0x4f}) {
    Piece p(Piece::Notchable(n));
    if (p.IsConnected()) {
      notchables.push_back(p);
    }
  }

  FitTable ft(notchables);

  Assemblies a(ft);
  a.Generate();
}
