#include <array>

#include "Translate.h"
#include "Piece.h"
#include "Partition.h"

class Fragment{
public:
  void Shift(Partition, Translate);

  bool CheckFree(Partition, Translate) const;
  bool CheckFit(Partition, const std::array<Piece, 6>&) const;
  bool operator==(const Fragment&) const;

private:
  std::array<Translate, 5> mDeltas;
};
