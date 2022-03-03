#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
TEST(Q6_Student, Return3D) {
  CPPLib c; 

  std::vector< std::vector< std::vector<int> > > input_1 = {{{1, 2}, {3, 4}}, {{5}, {6}, {}}, {{7, 8}}};
  std::vector<int> actual_1 = c.Flatten3DVector(input_1);
  std::vector<int> expected_1 = {1, 2, 3, 4, 5, 6, 7, 8};

  std::vector< std::vector< std::vector<int> > > input_2 = {};
  std::vector<int> actual_2 = c.Flatten3DVector(input_2);
  std::vector<int> expected_2 = {};
  
  EXPECT_EQ(expected_1, actual_1);
  EXPECT_EQ(expected_2, actual_2);
}