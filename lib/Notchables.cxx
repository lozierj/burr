#include <stdexcept>

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

std::vector<Piece> Notchables32()
{
  std::vector<Piece> vec;

  for (unsigned short h{0}; h <= 0xF; ++h) {
    for (unsigned short v : {0x0, 0x30, 0xC0}) {
      Piece p(Piece::Notchable(h + v));
      if (!(p.IsConnected())) throw std::logic_error("notchable32 not conn");
      vec.push_back(p);
    }
  }

  for (unsigned short h : {0x100, 0x200, 0x300}) {
    for (unsigned short v : {0x0, 0x30, 0xC0}) {
      Piece p(Piece::Notchable(h + v));
      if (!(p.IsConnected())) throw std::logic_error("notchable32 not conn");
      vec.push_back(p);
    }
  }

  for (unsigned short h : {0x0, 0x6, 0x300}) {
    for (unsigned short v : {0x10, 0x20, 0x40, 0x80}) {
      Piece p(Piece::Notchable(h + v));
      if (!(p.IsConnected())) throw std::logic_error("notchable32 not conn");
      vec.push_back(p);
    }
  }

  return vec;
}
