#include <vector>

#include "Test.h"
#include "../lib/Fragment.h"
#include "../lib/OffsetTable.h"

void Test_Fragment()
{
  const std::vector<Piece> ps{
    Piece::Notchable(0xCFu),
    Piece::Notchable(0x14u),
    Piece::Notchable(0x2Du),
    Piece::Notchable(0x3Cu),
    Piece::Notchable(0x0Fu),
    Piece::Notchable(0xC9u),

    Piece::Notchable(0x3Fu),
    Piece::Notchable(0x82u),
    Piece::Notchable(0x4Bu),
    Piece::Notchable(0xC3u),
    Piece::Notchable(0x39u)};

  const ReflectTable rt{ps};
  const OffsetTable ot{ps, rt};

  Assembly a{{0, 1, 2, 3, 4, 5}};

  Fragment f;
  test_equal(f.CheckFit(Partition(0b111u), a, ot), true);
  test_equal(f.CheckFit(Partition(0b10011u), a, ot), true);

  Fragment f1x{f};
  Partition s1x{0b000001u};
  f1x.Shift(s1x, {2, 0, 0});
  test_equal(f1x.CheckFit(s1x, a, ot), false);

  Partition s1{0b000010u};
  f.Shift(s1, {2, 0, 0});
  test_equal(f.CheckFit(s1, a, ot), true);

  Fragment f2x{f};
  Partition s2x{0b010000u};
  f2x.Shift(s2x, {-2, 0, 0});
  test_equal(f2x.CheckFit(s2x, a, ot), false);

  Partition s2{0b000001u};
  f.Shift(s2, {0, 2, 0});
  test_equal(f.CheckFit(s2, a, ot), true);

  Fragment f3x{f};
  Partition s3x{0b001000u};
  f3x.Shift(s3x, {-2, 0, 0});
  test_equal(f3x.CheckFit(s3x, a, ot), false);

  Partition s3{0b011000u};
  f.Shift(s3, {-2, 0, 0});
  test_equal(f.CheckFit(s3, a, ot), true);

  Fragment f4x{f};
  Partition s4x{0b001000u};
  f4x.Shift(s4x, {0, 0, 2});
  test_equal(f4x.CheckFit(s4x, a, ot), false);

  Partition s4{0b001000u};
  f.Shift(s4, {0, 0, -2});
  test_equal(f.CheckFit(s4, a, ot), true);

  Fragment f5x{f};
  Partition s5x{0b011111u};
  f5x.Shift(s5x, {2, 0, 0});
  test_equal(f5x.CheckFit(s5x, a, ot), false);

  Partition s5{0b001000u};
  f.Shift(s5, {0, 2, 0});
  test_equal(f.CheckFit(s5, a, ot), true);

  f.Shift(s5, {0, 2, 0});
  test_equal(f.CheckFree(s5, {0, 1, 0}), false);

  f.Shift(s5, {0, 2, 0});
  test_equal(f.CheckFree(s5, {0, 1, 0}), true);
}
