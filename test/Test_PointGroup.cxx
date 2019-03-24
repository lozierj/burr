#include "Test.h"
#include "../lib/Coordinates.h"
#include "../lib/Reflect.h"
#include "../lib/Rotate.h"
#include "../lib/PointGroup.h"

void Test_PointGroup()
{
  Coordinates o;
  Coordinates p{1, 3, -5};

  Reflect fI{0u};
  Reflect x{1u};
  Reflect xy{3u};

  Rotate oI{0u};
  Rotate a{1u};
  Rotate b{2u};

  PointGroup gI{fI, oI};
  PointGroup t{x, oI};
  PointGroup u{fI, a};
  PointGroup v(3u, 2u);

  test_equal(gI.IsProper(), true);
  test_equal(t.IsProper(), false);
  test_equal(v.IsProper(), true);

  test_equal(gI.Apply(o), o);
  test_equal(gI.Apply(p), p);

  test_equal(t.Apply(p), x.Apply(p));
  test_equal(u.Apply(p), a.Apply(p));
  test_equal(v.Apply(p), b.Apply(xy.Apply(p)));

  test_equal(v.Invert(p), xy.Invert(b.Invert(p)));

  test_equal(v.Apply(v.Invert(p)), p);
  test_equal(v.Invert(v.Apply(p)), p);
}
