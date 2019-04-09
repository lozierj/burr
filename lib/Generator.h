#include <array>
#include <vector>

#include "Assembly.h"
#include "FitTable.h"
#include "Position.h"
#include "ReflectTable.h"

class Generator{
public:
  Generator(const std::vector<Piece>& pcs)
      : mPieces{pcs}, mFitTable{pcs}, mReflectTable{pcs} {}

  void Generate();

private:
  void Iterate(Position);

  const std::vector<Piece> mPieces;
  const FitTable mFitTable;
  const ReflectTable mReflectTable;
  Assembly mAssembly;
};
