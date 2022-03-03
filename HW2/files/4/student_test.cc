
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
//-----------------------------------------------------------------------------
TEST(CapitalizeFirstLetter, test1) {
    CPPLib c;
    std::string name = "longhao yang";
    c.CapitalizeFirstLetter(name);
    EXPECT_EQ(name, "Longhao yang");
}

//-----------------------------------------------------------------------------
TEST(CapitalizeFirstLetter, test2) {
    CPPLib c;
    std::string name = "";
    c.CapitalizeFirstLetter(name);
    EXPECT_EQ(name, "");
}

//-----------------------------------------------------------------------------
TEST(CapitalizeFirstLetter, test3) {
    CPPLib c;
    std::string name = " Yang Longhao";
    c.CapitalizeFirstLetter(name);
    EXPECT_EQ(name, " Yang Longhao");
}

//-----------------------------------------------------------------------------
TEST(CapitalizeFirstLetter, test4) {
    CPPLib c;
    std::string greeting = " hello";
    c.CapitalizeFirstLetter(greeting);
    EXPECT_EQ(greeting, " Hello");
}