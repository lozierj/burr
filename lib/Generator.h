#include <array>

#include "Assembly.h"
#include "FitTable.h"
#include "Position.h"
#include "ReflectTable.h"

template<typename F>
class Generator{
public:
  Generator(const FitTable& ft, const ReflectTable& rt, F& f)
      : mFitTable{ft}, mReflectTable{rt}, mFunction{f} {}

  void Generate();
  F& GetFunc() {return mFunction;}

private:
  void Iterate(Position);

  const FitTable& mFitTable;
  const ReflectTable& mReflectTable;
  F& mFunction;
  Assembly mAssembly;
};

#include "Generator.tcc"
