#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(Fibonacci, Test_1) {
    int input = 5;
    EXPECT_EQ(Fibonacci(input), 5);
}

//-----------------------------------------------------------------------------
TEST(CoinChangeMemo, Test_1) {
    std::vector<int> coins = {1, 2, 5, 10};
    int amount = 11;
    EXPECT_EQ(CoinChangeMemo(coins, amount), 2);
}

//-----------------------------------------------------------------------------
TEST(CoinChangeTabulation, Test_1) {
    std::vector<int> coins = {1, 2, 5, 10};
    int amount = 11;
    EXPECT_EQ(CoinChangeTabulation(coins, amount), 2);
}

TEST(CoinChangeTabulation, Test2) {
    std::vector<int> coins = {8, 3, 1, 2};
    int amount = 3;
    EXPECT_EQ(CoinChangeTabulation(coins, amount), 1);
}

TEST(CoinChangeTabulation, Test3) {
    std::vector<int> coins = {2, 4, 6};
    int amount = 11;
    EXPECT_EQ(CoinChangeTabulation(coins, amount), -1);
}