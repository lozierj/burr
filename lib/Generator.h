#include <array>

#include "Assembly.h"
#include "FitTable.h"
#include "ReflectTable.h"
#include "Position.h"

class Generator{
public:
  Generator(const FitTable& ft, const ReflectTable& rt)
      : mFitTable{ft}, mReflectTable{rt} {}
  void Generate();

private:
  void Iterate(Position);

  const FitTable& mFitTable;
  const ReflectTable& mReflectTable;
  Assembly mAssembly;
  unsigned long mCount; //TODO make generate take a std ftn, make this static
};
