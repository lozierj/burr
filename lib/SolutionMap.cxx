#include <iostream>

#include "SolutionMap.h"

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
      std::cout << entry.first << "   L" << (int)(entry.second) << " ";
      for (Position i{0}; i < 6; ++i) std::cout << "  " << vec[entry.first[i]];
      std::cout << std::endl;
    }
  }
}
