#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
TEST(Q5_Student, ReturnIntro) {
  CPPLib cpplib;
  std::string expected = "Hello all, I'm Longhao Yang. \nMy email is longhaoy@usc.edu. \nI'm majoring in Machine Learning and Data Science under ECE department. \n";
  std::string actual = cpplib.PrintIntro(); 
  EXPECT_EQ(expected, actual);
}