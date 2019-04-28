#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

void Test_Apart();
void Test_Assembly();
void Test_Coordinates();
void Test_FitTable();
void Test_Fragment();
void Test_Generator();
void Test_Index();
void Test_Notchables();
void Test_OffsetTable();
void Test_Partition();
void Test_Piece();
void Test_PointGroup();
void Test_Position();
void Test_Reflect();
void Test_ReflectTable();
void Test_Rotate();
void Test_Subset();
void Test_TestFit();
void Test_TestReflect();

template<typename T, typename U>
void test_equal(T t, U u, std::string msg = "failed equality")
{
  if (t != u)
  {
    std::cout << msg << " " << t << " != " << u << std::endl;
  }
}

template<typename E, typename F>
void test_throw(F f, std::string msg = "didn't throw")
{
  try {
    f();
    std::cerr << msg << std::endl;
  } catch (const E&) {
  }
}
