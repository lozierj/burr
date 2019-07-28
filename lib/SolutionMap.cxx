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
    mMap.insert({s, {1, l}});
    return;
  }

  if (i->second.assms){

    if (i->second.level){ //if unique solution so far

      Level l{Apart(a, mOffset, mReflect)};

      if (l) i->second.assms = 0;
      else ++(i->second.assms);

    }else{ //if no solution so far

      Level l{Apart(a, mOffset, mReflect)};
      i->second.level = l;
      ++(i->second.assms);

    }
  }
}

void SolutionMap::Print(const std::vector<Piece>& vec) const
{
  for (auto& entry : mMap){
    if (entry.second.assms && entry.second.level){
      std::cout << entry.first
                << "  " << std::setw(3) << (int)(entry.second.level) << "L"
                << "  " << std::setw(3) << entry.first.Holes(vec) << "H"
                << "  " << std::setw(3) << (int)(entry.second.assms) << "A"
                << std::endl;
    }
  }
}
