// NOTE: Add your own q2 tests in this file
#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
TEST(Q2_Student, FindAverage) {
  CPPLib cpplib;
  double actual_1 = cpplib.FindAverage(std::vector<int> {});
  double expected_1 = -1;
  double actual_2 = cpplib.FindAverage(std::vector<int> {1, 2, 4, 5});
  double expected_2 = 3;
  double actual_3 = cpplib.FindAverage(std::vector<int> {1, 2, 3, 5});
  double expected_3 = 2.75;
  EXPECT_EQ(expected_1, actual_1);
  EXPECT_EQ(expected_2, actual_2);
  EXPECT_EQ(expected_3, actual_3);
}