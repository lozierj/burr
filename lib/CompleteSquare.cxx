#include <algorithm>
#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

#include "Apart.h"
#include "CompleteSquare.h"
#include "Piece.h"
#include "TestFit.h"

void CompleteSquare()
{
  std::ifstream s("data/ip2.tsv");
  s >> std::hex;

  using Pieces = std::array<Piece, 6>;
  std::vector<Pieces> data;

  constexpr unsigned lines{164};

  for (unsigned line{0}; line < lines; ++line){
    Pieces v;

    for (unsigned i{0}; i < 6; ++i){
      unsigned short n;
      s >> n;
      v[i] = Piece::Notchable(n);
    }

    data.push_back(v);
  }

  for (unsigned ai{0}; ai < lines; ++ai){
    for (unsigned bi{0}; bi < ai; ++bi){
      Pieces a{data[ai]};
      Pieces b{data[bi]};
      Pieces ab;
      Pieces ba;
      unsigned d{0};

      for (unsigned i{0}; i < 6; ++i){
        if (a[i] == b[i]){
          ab[i] = a[i];
          ba[i] = a[i];
        } else {
          switch (++d){
            case 1:
              ab[i] = a[i];
              ba[i] = b[i];
              break;
            case 2:
              ab[i] = b[i];
              ba[i] = a[i];
              break;
            default:
              assert(d >= 3);
          }
        }
      }

      if (d == 2){
        auto abi = std::find(data.begin(), data.end(), ab);
        auto bai = std::find(data.begin(), data.end(), ba);

        if (
               abi == data.end()
          //&& bai != data.end()
            && TestFit(ab)
            && Apart(ab) == 5){
          for (Piece p : ab) std::cout << " " << p;
          std::cout << std::endl;
        } else if (
               bai == data.end()
          //&& abi != data.end()
            && TestFit(ba)
            && Apart(ba) == 5){
          for (Piece p : ba) std::cout << " " << p;
          std::cout << std::endl;
        }
      }
    }
  }
}
