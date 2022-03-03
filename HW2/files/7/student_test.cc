#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"
// Write several test cases for each function.
//-----------------------------------------------------------------------------
TEST(SwapByPointer, test1) {
    CPPLib c;
    float val1 = 10.0;
    float val2 = 15.0;

    c.SwapByPointer(&val1, &val2);
    EXPECT_EQ(val1, 15.0);
    EXPECT_EQ(val2, 10.0);

}
//-----------------------------------------------------------------------------

TEST(SwapByReference, test2) {
    CPPLib c;
    float val1 = 10.0;
    float val2 = 15.0;

    float &i = val1;
    float &j = val2;

    c.SwapByReference(i, j);
    EXPECT_EQ(i, 15.0);
    EXPECT_EQ(j, 10.0);
}
//-----------------------------------------------------------------------------
