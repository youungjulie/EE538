#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
TEST(Q7_Student, ReturnSteps) {
  CPPLib c;
  int actual_1= c.climbStairs(-5);
  int actual_2= c.climbStairs(0);
  int actual_3= c.climbStairs(1);
  int actual_4= c.climbStairs(2);
  int actual_5= c.climbStairs(4);

  int expected_1 = -1; 
  int expected_2 = 0; 
  int expected_3 = 1; 
  int expected_4 = 2; 
  int expected_5 = 5;

  EXPECT_EQ(expected_1, actual_1);
  EXPECT_EQ(expected_2, actual_2);
  EXPECT_EQ(expected_3, actual_3);
  EXPECT_EQ(expected_4, actual_4);
  EXPECT_EQ(expected_5, actual_5);
  
}