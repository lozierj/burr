#include <array>

#include "Assembly.h"
#include "FitTable.h"
#include "Position.h"

class Generator{
public:
  Generator(const FitTable& ft) : mTable{ft}, mNum{mTable.GetSize()} {}
  void Generate();

private:
  void Iterate(Position);

  const FitTable& mTable;
  const Index mNum;
  Assembly mAssembly;
  unsigned long mCount;
};
