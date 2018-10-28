#include "Test.h"
#include "../lib/Coordinates.h"
#include "../lib/Rotate.h"

void Test_Rotate()
{
  Coordinates z;
  Coordinates d{1, 3, -5};
  Coordinates b{-2, 7, -4};

  Rotate o{0u};
  Rotate f{1u};
  Rotate r{2u};

  test_equal(o.Apply(z), z);
  test_equal(r.Apply(z), z);

  test_equal(f.Apply(d), Coordinates{-5, 1, 3});
  test_equal(f.Apply(b), Coordinates{-4, -2, 7});

  test_equal(r.Apply(d), Coordinates{3, -5, 1});
  test_equal(r.Apply(b), Coordinates{7, -4, -2});

  test_equal(f.Apply(r.Apply(d)), d);
  test_equal(r.Apply(f.Apply(b)), b);
  test_equal(f.Apply(f.Apply(b)), r.Apply(b));
}
