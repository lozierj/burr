#include <iostream>
#include <vector>

#include "Apart.h"
#include "Notchables.h"
#include "Permutor.h"
#include "TestReflect.h"
#include "TestFit.h"

unsigned Permutor(const std::array<Piece, 6>& input, unsigned index)
{
  static const std::vector<Piece> notchables{Notchables()};

  if (index == 6){
    unsigned a = Apart(input);

    //if (a == 5){
    //  std::cout << a << "   ";
    //  for (Piece p : input) std::cout << " " << p;
    //  std::cout << std::endl;
    //}

    return a ? 1 : 0;
  }

  unsigned ret{0};

  for (unsigned j{index}; j < 6; ++j){
    std::array<Piece, 6> working{input};

    std::swap(working[index], working[j]);
    if (TestFit(working, index)) ret += Permutor(working, index + 1);

    working[index] = FindReflect(working[index], Reflect(6), notchables);
    if (TestFit(working, index)) ret += Permutor(working, index + 1);
  }

  return ret;
}
