#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(BinaryTreeNode, Test_IsBST_1) {
    BinaryTreeNode one(1);
    BinaryTreeNode two(2);
    BinaryTreeNode three(3);
    BinaryTreeNode four(4);
    BinaryTreeNode five(5);
    BinaryTreeNode six(6);
    BinaryTreeNode seven(7);

    four.left = &two;
    four.right = &six;
    two.left = &one;
    two.right = &three;
    six.left = &five;
    six.right = &seven;
    
    EXPECT_EQ(IsBST(&four), true);
}

TEST(BinaryTreeNode, Test_IsBST_2) {
    BinaryTreeNode one(1);
    BinaryTreeNode two(2);
    BinaryTreeNode three(3);
    BinaryTreeNode four(4);
    BinaryTreeNode five(5);
    BinaryTreeNode six(6);
    BinaryTreeNode seven(7);

    four.left = &two;
    four.right = &five;
    two.left = &one;
    two.right = &three;
    five.left = &six;
    five.right = &seven;
    
    EXPECT_EQ(IsBST(&four), false);
}

//-----------------------------------------------------------------------------
TEST(BinaryTreeNode, FindStatistics) {
    BinaryTreeNode one(1);
    BinaryTreeNode two(2);
    BinaryTreeNode three(3);
    BinaryTreeNode four(4);
    BinaryTreeNode five(5);
    BinaryTreeNode six(6);
    BinaryTreeNode seven(7);

    four.left = &two;
    four.right = &six;
    two.left = &one;
    two.right = &three;
    six.left = &five;
    six.right = &seven;

    std::map<Statistics, int> expect = {
        {Statistics::kHeight, 3}, 
        {Statistics::kNumberOfLeaves, 4}, 
        {Statistics::kMin, 1}, 
        {Statistics::kMax, 7}, 
        {Statistics::kNumberOfSingleChildNodes, 0}, 
        {Statistics::kNumberOfNodes, 7}
    };
    
    EXPECT_EQ(FindStatistics(&four), expect);
}
