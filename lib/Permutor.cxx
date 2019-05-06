#include <iostream>

#include "Permutor.h"
#include "Apart.h"

Permutor::Permutor(Assembly a, const std::vector<Piece>& v)
  : mSet{}, mReflect{v}, mFit{v}, mEquiv{v}, mOffset{v, mReflect}, mPieces{v}
{
  Permute(a, 0);
}

void Permutor::Print()
{
  for (Assembly a : mSet){
    for (Position p{0}; p < 6; ++p) std::cout << mPieces[a[p]] << " ";
    std::cout << " L" << (int)Apart(a, mOffset, mReflect) << std::endl;
  }
}

void Permutor::Permute(Assembly a, Position p)
{
  if (p == 6 && a.Oriented(mReflect)){
    mSet.insert(a);
    return;
  }

  for (Position q{p}; q < 6; ++q){
    for (Index i{0}; i < mPieces.size(); ++i){
      if (mEquiv(a[q]) == mEquiv(i)){
        Assembly b{a};
        b[p] = i;
        if (p != q) b[q] = a[p];
        if (b.Fits(mFit, p)) Permute(b, p + 1);
      }
    }
  }
}
