#include "Test.h"

#include <exception>

int main()
{
  try {
    Test_Apart();
    Test_Assembly();
    Test_Coordinates();
    //Test_EquivTable(); TODO
    Test_FitTable();
    Test_Fragment();
    Test_Generator();
    Test_Notchables();
    Test_Partition();
    Test_Piece();
    Test_PointGroup();
    Test_Reflect();
    Test_ReflectTable();
    Test_Rotate();
    //Test_SpaceGroup(); TODO
    Test_Subset();
    Test_TestFit();
    Test_TestReflect();
    //Test_Translate(); TODO

    std::cout << "All tests completed." << std::endl;
    return 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
