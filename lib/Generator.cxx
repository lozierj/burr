#include <iostream>

#include "Apart.h"
#include "Generator.h"

void Generator::Generate()
{
  Iterate(0);
  std::cerr << std::endl;
  mMap.Print(mPieces);
}

void Generator::Iterate(Position k)
{
  if (k == 6){
    if (mAssembly.Oriented(mReflectTable)){
      mMap.Add(mAssembly);
    }
    return;
  }

  for (Index p{0}; p < mFitTable.GetSize(); ++p){
    if (k == 0) std::cerr << "." << std::flush;

    mAssembly[k] = p;
    if (mAssembly.Fits(mFitTable, k)) Iterate(k + 1);
  }
}

