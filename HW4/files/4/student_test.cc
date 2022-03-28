#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(knapSack01NoDynamicProgramming, Test1) {
    std::vector<int> weights = {1, 2, 1, 12, 4};
    std::vector<int> values = {1, 2, 2, 4, 10};
    int capacity = 15;
    int result = knapSack01NoDynamicProgramming(weights, values, capacity);
    EXPECT_EQ(result, 15);
}

TEST(knapSack01Memo, Test1) {
    std::vector<int> weights = {1, 2, 1, 12, 4};
    std::vector<int> values = {1, 2, 2, 4, 10};
    int capacity = 15;
    int result = knapSack01Memo(weights, values, capacity);
    EXPECT_EQ(result, 15);
}

TEST(knapSack01Tablulation, Test1) {
    std::vector<int> weights = {1, 2, 1, 12, 4};
    std::vector<int> values = {1, 2, 2, 4, 10};
    int capacity = 15;
    int result = knapSack01Tablulation(weights, values, capacity);
    EXPECT_EQ(result, 15);
}