#include <iostream>

#include "Apart.h"
#include "Generator.h"

void Generator::Generate()
{
  Iterate(0);
  std::cerr << std::endl;
}

void Generator::Iterate(Position k)
{
  if (k == 6){
    if (mAssembly.Oriented(mReflectTable)){
      std::array<Piece, 6> pieces;
      for (unsigned i{0}; i<6; ++i) pieces[i] = mPieces[mAssembly[i]];
      std::cout << static_cast<int>(Apart(pieces));
    }
    return;
  }

  for (Index p{0}; p < mFitTable.GetSize(); ++p){
    if (k == 0) std::cerr << "." << std::flush;

    mAssembly[k] = p;
    if (mAssembly.Fits(mFitTable, k)) Iterate(k + 1);
  }
}

