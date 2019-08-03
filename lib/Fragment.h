#include <array>

#include "Assembly.h"
#include "Translate.h"
#include "OffsetTable.h"
#include "Partition.h"

class Fragment{
public:
  void Shift(Partition, Translate);

  bool CheckFree(Partition move, Partition stat, Translate) const;
  bool CheckFree(Partition move, Translate) const;
  bool CheckFit(Partition move, Partition stat,
                Assembly, const OffsetTable&) const;
  bool CheckFit(Partition move, Assembly, const OffsetTable&) const;
  bool operator==(const Fragment&) const;

  friend std::ostream& operator<<(std::ostream&, const Fragment&);

private:
  std::array<Translate, 5> mDeltas;
};

std::ostream& operator<<(std::ostream&, const Fragment&);
