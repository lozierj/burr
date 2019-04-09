#include <fstream>
#include <array>
#include <vector>

#include "Test.h"
#include "../lib/Piece.h"

void Test_Subset()
{
  std::ifstream s("data/ip2.tsv");
  s >> std::hex;

  using Pieces = std::array<Piece, 6>;

  std::vector<Pieces> pieces;

  for(int line{1}; line <= 164; ++line){
   Pieces v;

    for (unsigned i{0}; i < 6; ++i){
      unsigned short n;
      s >> n;
      v[i] = Piece::Notchable(n);
    }

    pieces.push_back(v);

  }

  int count{0};

  for (unsigned b{0}; b < pieces.size(); ++b){
    for (unsigned a{0}; a < pieces.size(); ++a){
      if (   pieces[a][0].IsSubset(pieces[b][0])
          && pieces[a][1].IsSubset(pieces[b][1])
          && pieces[a][2].IsSubset(pieces[b][2])
          && pieces[a][3].IsSubset(pieces[b][3])
          && pieces[a][4].IsSubset(pieces[b][4])
          && pieces[a][5].IsSubset(pieces[b][5])){
        if (a != b) ++count;
      }
    }
  }

  test_equal(count, 134); //not verified
}
