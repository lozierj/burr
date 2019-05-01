#include <cassert>
#include <stdexcept>

#include "EquivTable.h"
#include "Reflect.h"
#include "TestReflect.h"

EquivTable::EquivTable(const std::vector<Piece>& vec)
{
  unsigned n(vec.size());

  mTable.reserve(n);

  for (Index i{0}; i < n; ++i){
    std::vector<Piece> equivs;
    equivs.push_back(vec[i]);

    if (vec[i].IsAmbiguous()){
      equivs.push_back(vec[i].Twist());
      equivs.push_back(vec[i].Twist().Twist());
      equivs.push_back(vec[i].Twist().Twist().Twist());
    }

    Index lowest{i};

    for (Index j{0}; j < n; ++j){
      for (Piece equiv : equivs){
        if (equiv == vec[j]){
          lowest = std::min(lowest, j);
        }

        if (TestReflect(equiv, vec[j], Reflect(6u))){
          lowest = std::min(lowest, j);
        }
      }
    }

    mTable.push_back(lowest);
  }

  if (mTable.size() != n) throw std::logic_error("eqiv table not built");
}

Index EquivTable::operator()(Index i) const
{
  assert(i < mTable.size());
  return mTable[i];
}
