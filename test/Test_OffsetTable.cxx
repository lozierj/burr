#include <iostream>
#include <vector>

#include "Test.h"
#include "../lib/TestFit.h"
#include "../lib/Notchables.h"
#include "../lib/OffsetTable.h"
#include "../lib/ReflectTable.h"

void Test_OffsetTable()
{
  const std::vector<Piece> v{Notchables32()};

  ReflectTable rt{v};
  OffsetTable ot{v, rt};
  int i{0};

  for (Index ai{0}; ai < v.size(); ++ai){
    for (Index bi{0}; bi < v.size(); ++bi){
      for (Position ap{0}; ap < 6; ++ap){
        for (Position bp{0}; bp < 6; ++bp){
          for (Translate::Type x{-12}; x <= 12; x += 2){
            for (Translate::Type y{-12}; y <= 12; y += 2){
              for (Translate::Type z{-12}; z <= 12; z += 2){
                if (ap != bp && !(++i % 143)){
                  bool corr{TestFit(v[ai], ap, v[bi], bp, {x, y, z})};
                  bool table{ot(ai, ap, bi, bp, {x, y, z})};
                  test_equal(corr, table);
                }
              }
            }
          }
        }
      }
    }
  }
}
