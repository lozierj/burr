#include <array>

#include "Assembly.h"
#include "FitTable.h"
#include "Position.h"

class Generator{
public:
  Generator(const FitTable& ft) : mFitTable{ft} {}
  void Generate();

private:
  void Iterate(Position);

  const FitTable& mFitTable;
  Assembly mAssembly;
  unsigned long mCount; //TODO make generate take a std ftn, make this static
};
