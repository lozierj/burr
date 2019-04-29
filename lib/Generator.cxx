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
      int level{Apart(mAssembly, mOffsetTable)};

      if (level){
        Assembly s{mAssembly};
        s.ToSetForm(mEquivTable);
        std::cout << s << "\t L" << level << "\t" << mAssembly << std::endl;
      }
    }
    return;
  }

  for (Index p{0}; p < mFitTable.GetSize(); ++p){
    //if (k == 0) std::cerr << "." << std::flush;

    mAssembly[k] = p;
    if (mAssembly.Fits(mFitTable, k)) Iterate(k + 1);
  }
}

