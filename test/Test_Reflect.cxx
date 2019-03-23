#include "Test.h"
#include "../lib/Coordinates.h"
#include "../lib/Reflect.h"

void Test_Reflect()
{
  Coordinates n;
  Coordinates d{1, 3, -5};

  Reflect o{0u};
  Reflect x{1u};
  Reflect z{4u};
  Reflect xy{3u};
  Reflect yz{6u};
  Reflect xz{5u};

  test_equal(o.IsProper(), true);
  test_equal(x.IsProper(), false);
  test_equal(z.IsProper(), false);
  test_equal(yz.IsProper(), true);

  test_equal(o.Apply(n), n);
  test_equal(o.Apply(d), d);
  test_equal(xy.Apply(n), n);

  test_equal(xy.Apply(d), Coordinates{-1, -3, -5});
  test_equal(yz.Invert(d), Coordinates{1, -3, 5});

  test_equal(xy.Apply(xy.Apply(d)), d);
  test_equal(xy.Apply(yz.Invert(d)), xz.Apply(d));
}
