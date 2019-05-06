#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <vector>

#include "Test.h"
#include "../lib/Apart.h"
#include "../lib/Piece.h"
#include "../lib/Notchables.h"
#include "../lib/OffsetTable.h"
#include "../lib/ReflectTable.h"

void Test_Apart()
{
  const std::vector<Piece> pieces{Notchables()};
  const ReflectTable rt{pieces};
  const OffsetTable ot{pieces, rt};

  std::ifstream s("data/ip2.tsv");
  s >> std::hex;

  for(int line{1}; line <= 164; ++line){
   Assembly a;

    for (unsigned i{0}; i < 6; ++i){
      unsigned short n;
      s >> n;
      auto it = std::find(pieces.begin(), pieces.end(), Piece::Notchable(n));
      if (it == pieces.end()) throw std::logic_error("piece not in set");
      a[i] = it - pieces.begin();
    }

    test_equal(Apart(a, ot, rt), 5);
  }
}
