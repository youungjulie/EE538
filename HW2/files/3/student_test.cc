#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(Calculate, test1) { 
    CPPLib c;
    Operation add = Operation::add; 
    int a = 5; 
    int b = 9;
    float result = c.Calculate(a, b, add);
    EXPECT_EQ(result, 14); 

}

//-----------------------------------------------------------------------------
TEST(Calculate, test2) {
    CPPLib s;
    Operation subtract = Operation::subtract; 
    int a = 5; 
    int b = 9;
    float result = s.Calculate(a, b, subtract);
    EXPECT_EQ(result, -4); 
}

//-----------------------------------------------------------------------------
TEST(Calculate, test3) {
    CPPLib s;
    Operation multiplication = Operation::multiplication; 
    int a = 5; 
    int b = 9;
    float result = s.Calculate(a, b, multiplication);
    EXPECT_EQ(result, 45); 
}

//-----------------------------------------------------------------------------
TEST(Calculate, test4) {
    CPPLib s;
    int a = 5; 
    int b = 2;
    float result = s.Calculate(a, b, Operation::division);
    EXPECT_EQ(result, 2.5); 
}

//-----------------------------------------------------------------------------
TEST(Calculate, test5) {
    CPPLib s;
    int a = 5; 
    int b = 2;
    float result = s.Calculate(a, b, Operation::bitwise_AND);
    EXPECT_EQ(result, 0); 
}

//-----------------------------------------------------------------------------
TEST(Calculate, test6) {
    CPPLib s;
    int a = 5; 
    int b = 2;
    float result = s.Calculate(a, b, Operation::bitwise_OR);
    EXPECT_EQ(result, 7); 
}

//-----------------------------------------------------------------------------
TEST(Calculate, test7) {
    CPPLib s;
    int a = 5; 
    int b = 2;
    float result = s.Calculate(a, b, Operation::bitwise_XOR);
    EXPECT_EQ(result, 7);
}

//-----------------------------------------------------------------------------
TEST(Calculate, test8) {
    CPPLib s;
    int a = 5; 
    int b = 2;
    float result = s.Calculate(a, b, Operation::shift_left);
    EXPECT_EQ(result, 20);
}

//-----------------------------------------------------------------------------
TEST(Calculate, test9) {
    CPPLib s;
    int a = 5; 
    int b = 2;
    float result = s.Calculate(a, b, Operation::shift_right);
    EXPECT_EQ(result, 1);
}