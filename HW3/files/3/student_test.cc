#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(Queue, Test_copy) {
    Queue que;

    // enqueue
    que.Enqueue(1);
    que.Enqueue(2);
    que.Enqueue(3);
    std::vector<int> expect_1 = {1, 2, 3};
    EXPECT_EQ(que.GetVec(), expect_1); 

    // dequeue
    bool remove_third = que.Dequeue();
    EXPECT_EQ(remove_third, true); 

    std::vector<int> expect_2 = {2, 3};
    EXPECT_EQ(que.GetVec(), expect_2); 

    // front
    int first = que.Front();
    EXPECT_EQ(first, 2); 

    // isempty
    EXPECT_EQ(que.IsEmpty(), false); 
    que.Dequeue();
    que.Dequeue();
    EXPECT_EQ(que.IsEmpty(), true); 

    // front
    int empty = que.Front();
    EXPECT_EQ(empty, -1); 

}
