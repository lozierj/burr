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
    if (vec[i].IsAmbiguous()) throw std::logic_error("TODO: not implemented");
    for (Index j{0}; j < n; ++j){
      if (TestReflect(vec[i], vec[j], Reflect(6u))){
        mTable.push_back(std::min(i, j));
        break;
      }
    }

    assert(mTable.size() == n);
  }
}

Index EquivTable::operator()(Index i) const
{
  assert(i < mTable.size());
  return mTable[i];
}
