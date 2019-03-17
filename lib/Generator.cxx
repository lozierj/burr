#include <iostream>
#include <iomanip>

#include "Generator.h"

void Generator::Generate()
{
  mCount = 0;
  Iterate(0);
  std::cout << "\n" << mCount << std::endl;
}

void Generator::Iterate(Position k)
{
  if (k == 6){
    ++mCount;
    return;
  }

  for (Index p{0}; p < mFitTable.GetSize(); ++p){
    if (k == 0) std::cout << "." << std::flush;

    mAssembly[k] = p;
    if (mAssembly.Fits(mFitTable, k)) Iterate(k + 1);
  }
}

