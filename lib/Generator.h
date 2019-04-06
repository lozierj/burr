#include <array>
#include <vector>

#include "Assembly.h"
#include "FitTable.h"
#include "Position.h"
#include "ReflectTable.h"

template<typename F>
class Generator{
public:
  Generator(const std::vector<Piece>& pcs, F& f)
      : mPieces{pcs}, mFitTable{pcs}, mReflectTable{pcs}, mFunction{f} {}

  void Generate();

private:
  void Iterate(Position);

  const std::vector<Piece> mPieces;
  const FitTable mFitTable;
  const ReflectTable mReflectTable;
  F& mFunction;
  Assembly mAssembly;
};

#include "Generator.tcc"
