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
  assert(mTable[0u].size() == n);
  assert(mTable[6u].size() == n);
  if (mTable[2u].size() != n) mTable[2u].clear();
  if (mTable[4u].size() != n) mTable[4u].clear();
}

Index ReflectTable::operator()(Index i, Reflect r) const
{
  assert(i < mTable[r.GetRep()].size());
  return mTable[r.GetRep()][i];
}
