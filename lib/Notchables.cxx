#include "Notchables.h"

std::vector<Piece> Notchables()
{
  std::vector<Piece> vec;

  for (unsigned short n{0}; n < 1<<10; ++n) {
    Piece p(Piece::Notchable(n));

    if (p.IsConnected()) {
      vec.push_back(p);
    }
  }

  return vec;
}
