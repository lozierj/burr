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
      Assembly s{mAssembly};
      s.ToSetForm(mEquivTable);
      int level{Apart(pieces)};

      if (level == 7){
        std::cout << s << "\t L" << level << "\t";
        for (Piece p : pieces) std::cout << " " << p;
        std::cout << std::endl;
      }
    }
    return;
  }

  for (Index p{0}; p < mFitTable.GetSize(); ++p){
    if (k == 0) std::cerr << "." << std::flush;

    mAssembly[k] = p;
    if (mAssembly.Fits(mFitTable, k)) Iterate(k + 1);
  }
}

