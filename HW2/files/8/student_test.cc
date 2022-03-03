#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"

// Write several test cases for each function.
//-----------------------------------------------------------------------------
TEST(UniqueVectorNotBySet, test1) {
    CPPLib c;
    std::vector<int> vec = {1, 2, 2, 3, 4, 5, 3, 0};
    c.UniqueVectorNotBySet(vec);
    std::vector<int> exp = {1, 2, 3, 4, 5, 0};
    EXPECT_EQ(vec, exp);

    std::vector<int> vec_1 = {};
    c.UniqueVectorNotBySet(vec_1);
    std::vector<int> exp_1 = {};
    EXPECT_EQ(vec_1, exp_1);
}

//-----------------------------------------------------------------------------
TEST(UniqueVectorBySet, test1) {
    CPPLib c;
    std::vector<int> vec = {1, 2, 2, 3, 4, 5, 3, 0};
    c.UniqueVectorBySet(vec);
    std::vector<int> exp = {0, 1, 2, 3, 4, 5};
    EXPECT_EQ(vec, exp);

    std::vector<int> vec_1 = {};
    c.UniqueVectorBySet(vec_1);
    std::vector<int> exp_1 = {};
    EXPECT_EQ(vec_1, exp_1);
}

//-----------------------------------------------------------------------------
TEST(IntersectVectors, test2) {
    CPPLib c;
    std::vector<int> vec_1 = {1, 2, 2, 3};
    std::vector<int> vec_2 = {1, 2, 2, 3};
    std::vector<int> actual = c.IntersectVectors(vec_1, vec_2);
    std::vector<int> exp = {1, 2, 3};
    EXPECT_EQ(actual, exp);

    std::vector<int> vec_3 = {1, 2, 2, 3, 4, 5, 6};
    std::vector<int> vec_4 = {1, 2, 3};
    std::vector<int> actual_1 = c.IntersectVectors(vec_3, vec_4);
    std::vector<int> exp_1 = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(actual_1, exp_1);

    std::vector<int> vec_5 = {};
    std::vector<int> vec_6 = {1, 2, 3};
    std::vector<int> actual_2 = c.IntersectVectors(vec_5, vec_6);
    std::vector<int> exp_2 = {1, 2, 3};
    EXPECT_EQ(actual_2, exp_2);

    std::vector<int> vec_7 = {};
    std::vector<int> vec_8 = {};
    std::vector<int> actual_3 = c.IntersectVectors(vec_7, vec_8);
    std::vector<int> exp_3 = {};
    EXPECT_EQ(actual_3, exp_3);

}