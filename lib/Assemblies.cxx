#include <iostream>
#include <iomanip>

#include "Assemblies.h"

void Assemblies::Generate()
{
  mCount = 0;
  Iterate(0);
  std::cout << mCount << std::endl;
}

void Assemblies::Iterate(unsigned k)
{
  if (k == 6){
    //for (unsigned l{0}; l < k; ++l){
    //  std::cout << std::setw(3) << mAssembly[l] << " ";
    //}

    //std::cout << std::endl;

    ++mCount;

    return;
  }

  //if (k < 3){
  //  for (unsigned l{0}; l < k; ++l){
  //    std::cout << std::setw(3) << mAssembly[l] << " ";
  //  }
  //  std::cout << std::endl;
  //}


  for (FitTable::Index p{0}; p < mNum; ++p){
    if (k == 0) std::cout << p << std::endl;

    if (Fits(p, k)) {
      mAssembly[k] = p;
      Iterate(k + 1);
    }
  }
}

bool Assemblies::Fits(FitTable::Index p, unsigned k)
{
  for (unsigned l{0}; l < k; ++l){
    if (!(mTable(mAssembly[l], l, p, k))) return false;
  }

  return true;
}
