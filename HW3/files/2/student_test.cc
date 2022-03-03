#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(CPPLib, Test_VaildBrackets) {
    CPPLib c;
    std::map<std::string, bool> examples = {
        {"(a+b)", true},
        {"(a+b)[c*d]{5g+h}", true},
        {"(a+b]", false},
        {"(7h+[5c)+7]", false},
        {"{2k+[5j]}", true},
        {"{2k++[5--*j]}", true},
    }; 
    
    for (auto it = examples.begin(); it != examples.end(); ++it) {
        std::cout << it->first << std::endl;  
        bool actual = c.CheckValidExpression(it->first);
        bool expect = it->second; 
        EXPECT_EQ(actual, expect);
    }

}

TEST(CPPLib, Test_IsPalindrome) {
    CPPLib c;
    std::map<std::string, bool> examples = {
        {"abba", true},
        {"abcba", true},
        {"abbba", true},
        {"abcde", false},
        {"", true}
    }; 
    
    for (auto it = examples.begin(); it != examples.end(); ++it) {
        std::cout << it->first << std::endl;  
        bool actual = c.IsPalindrome(it->first);
        bool expect = it->second; 
        EXPECT_EQ(actual, expect);
    }

}

TEST(CPPLib, Test_Oddchar) {
    CPPLib c;
    std::map<std::string, int> examples = {
        {"abba", 0},
        {"abcba", 99},
        {"abbba", 98},
        {"", 0}
    }; 
    
    for (auto it = examples.begin(); it != examples.end(); ++it) {
        std::cout << it->first << std::endl;  
        bool actual = c.OddChar(it->first);
        bool expect = it->second; 
        EXPECT_EQ(actual, expect);
    }
}