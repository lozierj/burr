#include <array>

#include "FitTable.h"

class Assemblies{
public:
  Assemblies(const FitTable& ft) : mTable{ft}, mNum{mTable.GetSize()} {}
  void Generate();

private:
  void Iterate(unsigned);
  bool Fits(FitTable::Index, unsigned);

  const FitTable& mTable;
  const FitTable::Index mNum;
  std::array<FitTable::Index, 6> mAssembly;
  unsigned long mCount;
};
