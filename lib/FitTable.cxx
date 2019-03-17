#include <cassert>

#include "FitTable.h"
#include "TestFit.h"

FitTable::FitTable(const std::vector<Piece>& vec)
{
  unsigned n(vec.size());

  for (unsigned ap{0}; ap < 6; ++ap){
    mTable[ap].reserve(n);

    for (Index ai{0}; ai < n; ++ai){
      mTable[ap].emplace_back();

      for (unsigned bp{0}; bp < 6; ++bp){
        mTable[ap][ai][bp].reserve(n);

        for (Index bi{0}; bi < n; ++bi){
          mTable[ap][ai][bp].push_back(TestFit(vec[ai], ap, vec[bi], bp));
        }
      }
    }
  }
}

bool FitTable::operator()(Index ai, Position ap, Index bi, Position bp) const
{
  assert(ap < 6 && bp < 6 && ai < mTable[0].size() && bi < mTable[0].size());
  return mTable[ap][ai][bp][bi];
}
