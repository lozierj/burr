#include <cassert>

#include "ReflectTable.h"
#include "Reflect.h"
#include "TestReflect.h"

ReflectTable::ReflectTable(const std::vector<Piece>& vec)
{
  unsigned n(vec.size());

  for (Reflect r : {Reflect(0u), Reflect(2u), Reflect(4u), Reflect(6u)}){
    mTable[r.GetRep()].reserve(n);

    for (Index i{0}; i < n; ++i){
      for (Index j{0}; j < n; ++j){
        if (TestReflect(vec[i], vec[j], r)){
          mTable[r.GetRep()].push_back(j);
          break;
        }
      }
    }
  }
}

Index ReflectTable::operator()(Index i, Reflect r) const
{
  assert(i < mTable[0].size());
  return mTable[r.GetRep()][i];
}
