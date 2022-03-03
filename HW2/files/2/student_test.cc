#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

// -----------------------------------------------------------------------------
// Write some test cases for each function.
// -----------------------------------------------------------------------------
TEST(IndexOfFirstSpace, test1) {
    CPPLib s;
    std::string name = "Longhao Yang"; 
    std::string greeting = " Hi "; 
    std::string greeting_1 = "Hello ";
    std::string space = "  ";

    EXPECT_EQ(s.IndexOfFirstSpace(name), 7);
    EXPECT_EQ(s.IndexOfFirstSpace(greeting), 0);
    EXPECT_EQ(s.IndexOfFirstSpace(greeting_1), 5);
    EXPECT_EQ(s.IndexOfFirstSpace(space), 0);

}


//-----------------------------------------------------------------------------
TEST(SeparateFirstAndLastNames, test2) {
    CPPLib s;
    std::string name_1 = "Longhao Yang"; 
    std::string name_2 = "Longhao"; 
    std::string name_3 = " Yang";
    std::string name_4 = "  ";
    std::string first_name = "";
    std::string last_name = "";

    s.SeparateFirstAndLastNames(name_4, first_name, last_name);
    std::string exp1 = "";
    std::string exp2 = " ";
    EXPECT_EQ(first_name, exp1);
    EXPECT_EQ(last_name, exp2);
}


//-----------------------------------------------------------------------------
TEST(NumberOfVowels, test3) {
    CPPLib s;
    std::string name_1 = "Longhao Yang"; 
    EXPECT_EQ(s.NumberOfVowels(name_1), 4);
    std::string name_2 = "Aello, World! "; 
    EXPECT_EQ(s.NumberOfVowels(name_2), 4);
}

//-----------------------------------------------------------------------------
TEST(NumberOfConsonants, test4) {
    CPPLib s;
    std::string name_1 = "Longhao Yang~"; 
    EXPECT_EQ(s.NumberOfConsonants(name_1), 7);
    std::string name_2 = "Aello, World! "; 
    EXPECT_EQ(s.NumberOfConsonants(name_2), 6);
}

//-----------------------------------------------------------------------------
TEST(Reverse, test5) {
    CPPLib s; 
    std::string name = "Longhao Yang"; 
    s.Reverse(name);
    EXPECT_EQ(name, "gnaY oahgnoL");
    
    std::string greeting = "Hello World! "; 
    s.Reverse(greeting);
    EXPECT_EQ(greeting, " !dlroW olleH");
}