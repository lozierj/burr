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
    Level l{Apart(a, mOffset, mReflect)};
    if (l) mMap.insert({s, {1, l, 1}});
    else mMap.insert({s, {1, l, 0}});
    return;
  }

  if (i->second.level)
  {
    Level l{Apart(a, mOffset, mReflect)};

    if (l){
      i->second.level = std::min(i->second.level, l);
      ++(i->second.solns);
    }

    ++(i->second.assms);
  }

  if (i->second.level == 0)
  {
    Level l{Apart(a, mOffset, mReflect)};

    i->second.level = l;
    if (l){
      ++(i->second.solns);
    }

    ++(i->second.assms);
  }
}

void SolutionMap::Print(const std::vector<Piece>& vec) const
{
  for (auto& entry : mMap){
    if (entry.second.level){
      std::cout << entry.first
                << "  " << std::setw(3) << (int)(entry.second.level) << "L"
                << "  " << std::setw(3) << entry.first.Holes(vec) << "H"
                << "  " << std::setw(3) << (int)(entry.second.assms) << "A"
                << "  " << std::setw(3) << (int)(entry.second.solns) << "S"
                << std::endl;
    }
  }
}
