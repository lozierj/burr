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
    SubLevel l{SubApart(a, mOffset, mReflect)};
    mMap.insert({s, {1, l}});
    return;
  }

  if (i->second.assms){ // zero assms means multiple solutions

    if (i->second.level.mLevel){ //if unique solution so far

      SubLevel l{SubApart(a, mOffset, mReflect)};

      if (l.mLevel) i->second.assms = 0;
      else ++(i->second.assms);

    }else{ //if no solution so far

      SubLevel l{SubApart(a, mOffset, mReflect)};
      i->second.level = l; //zero level means no solution
      ++(i->second.assms); //update assms in either case

    }
  }
}

void SolutionMap::Print(const std::vector<Piece>& vec) const
{
  for (auto& entry : mMap){
    if (entry.second.assms && entry.second.level.mLevel){
      std::cout << entry.first
                << "  " << std::setw(3) << entry.second.level << "L"
                << "  " << std::setw(3) << entry.first.Holes(vec) << "H"
                << "  " << std::setw(3) << (int)(entry.second.assms) << "A"
                << std::endl;
    }
  }
}
