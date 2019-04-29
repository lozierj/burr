#include <array>

#include "Assembly.h"
#include "Translate.h"
#include "OffsetTable.h"
#include "Partition.h"

class Fragment{
public:
  void Shift(Partition, Translate);

  bool CheckFree(Partition, Translate) const;
  bool CheckFit(Partition, Assembly, const OffsetTable&) const;
  bool operator==(const Fragment&) const;

private:
  std::array<Translate, 5> mDeltas;
};
