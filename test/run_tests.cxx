#include "Test.h"

#include <exception>

int main()
{
  try {
    Test_Piece();
    Test_Coordinates();
    Test_Rotate();
    Test_Reflect();
    Test_PointGroup();
    Test_TestFit();
    Test_FitTable();
    Test_TestReflect();
    Test_ReflectTable();

    std::cout << "All tests completed." << std::endl;
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
