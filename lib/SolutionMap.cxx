#include <iostream>
#include <iomanip>

#include "SolutionMap.h"
#include "Permutor.h"

void SolutionMap::Add(const Assembly& a)
{
  Assembly s{a};
  s.ToSetForm(mEquiv);

  using Iterator = Map::iterator;
  Iterator i{mMap.find(s)};

  if (i == mMap.end()){
    Level l{Apart(a, mOffset)};
    if (l) mMap.insert({s, l});
    return;
  }

  if (i->second)
  {
    Level l{Apart(a, mOffset)};
    if (l) i->second = 0;
  }
}

void SolutionMap::Print(const std::vector<Piece>& vec) const
{
  for (auto& entry : mMap){
    if (entry.second > 4){
      Permutor perm{entry.first, vec};
      std::cout << entry.first
                << "  " << std::setw(3) << (int)(entry.second) << "L"
                << "  " << std::setw(3) << perm.Count() << "A"
                << std::endl;
    }
  }
}
