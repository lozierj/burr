#include "Test.h"

#include <exception>

int main()
{
  try {
    Test_Assembly();
    Test_Coordinates();
    Test_FitTable();
    Test_Generator();
    Test_Notchables();
    Test_Piece();
    Test_PointGroup();
    Test_Reflect();
    Test_ReflectTable();
    Test_Rotate();
    Test_TestFit();
    Test_TestReflect();
    Test_Partition();
    Test_Fragment();
    Test_Apart();

    std::cout << "All tests completed." << std::endl;
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
