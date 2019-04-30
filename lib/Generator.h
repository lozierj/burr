#include <vector>

#include "Assembly.h"
#include "EquivTable.h"
#include "FitTable.h"
#include "OffsetTable.h"
#include "Position.h"
#include "ReflectTable.h"
#include "SolutionMap.h"

class Generator{
public:
  Generator(const std::vector<Piece>& pcs)
  : mPieces{pcs},
    mFitTable{pcs},
    mReflectTable{pcs},
    mEquivTable{pcs},
    mOffsetTable{pcs, mReflectTable},
    mMap{mEquivTable, mOffsetTable}
  {}

  void Generate();

private:
  void Iterate(Position);

  const std::vector<Piece> mPieces;
  const FitTable mFitTable;
  const ReflectTable mReflectTable;
  const EquivTable mEquivTable;
  const OffsetTable mOffsetTable;
  SolutionMap mMap;
  Assembly mAssembly;
};
