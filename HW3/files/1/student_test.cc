#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

// -----------------------------------------------------------------------------
// Write some test cases for each function.
// -----------------------------------------------------------------------------
TEST(MyVector, Test_constructor) {
    MyVector v;
    std::vector<int> actual = v.ConvertToStdVector();
    std::vector<int> expect(0);
    EXPECT_EQ(actual, expect);

    int actual_size = v.size();
    int expect_size = 0;
    EXPECT_EQ(actual_size, expect_size);

    ErrorCode actual_error = v.get_error();
    ErrorCode expect_error = ErrorCode::kNoError;
    EXPECT_EQ(actual_error, expect_error);

}

TEST(MyVector, Test_constructor_with_size) {
    MyVector vec(3);
    std::vector<int> actual = vec.ConvertToStdVector();
    std::vector<int> expect(3);
    EXPECT_EQ(actual, expect);

    int actual_size = vec.size();
    int expect_size = 3;
    EXPECT_EQ(actual_size, expect_size);

    ErrorCode actual_error = vec.get_error();
    ErrorCode expect_error = ErrorCode::kNoError;
    EXPECT_EQ(actual_error, expect_error);

}

TEST(MyVector, Test_Copy_Constructor) {
    MyVector vec_1; 
    vec_1.push_back(1);
    vec_1.push_back(2);
    MyVector copy_vec(vec_1);

    std::vector<int> actual = copy_vec.ConvertToStdVector();
    std::vector<int> expect = {1, 2};
    EXPECT_EQ(actual, expect);

    int actual_size = copy_vec.size();
    int expect_size = 2;
    EXPECT_EQ(actual_size, expect_size);

    ErrorCode actual_error = copy_vec.get_error();
    ErrorCode expect_error = ErrorCode::kNoError;
    EXPECT_EQ(actual_error, expect_error);

}


TEST(MyVector, Test_push_back) {
    MyVector vec_1(0);
    vec_1.push_back(1); 
    vec_1.push_back(2); 
    vec_1.push_back(3); 


    std::vector<int> actual = vec_1.ConvertToStdVector();
    std::vector<int> expect = {1, 2, 3};
    EXPECT_EQ(actual, expect);

    int actual_size = vec_1.size();
    int expect_size = 3;
    EXPECT_EQ(actual_size, expect_size);

    ErrorCode actual_error = vec_1.get_error();
    ErrorCode expect_error = ErrorCode::kNoError;
    EXPECT_EQ(actual_error, expect_error);

}


TEST(MyVector, Test_pop_back) {
    MyVector vec_1(3);
    vec_1.pop_back(); 
    vec_1.pop_back(); 
    vec_1.pop_back(); 


    std::vector<int> actual = vec_1.ConvertToStdVector();
    std::vector<int> expect = {};
    EXPECT_EQ(actual, expect);

    int actual_size = vec_1.size();
    int expect_size = 0;
    EXPECT_EQ(actual_size, expect_size);


    vec_1.pop_back();
    ErrorCode actual_error = vec_1.get_error();
    ErrorCode expect_error = ErrorCode::kPopFromEmptyVector;
    EXPECT_EQ(actual_error, expect_error);

}


TEST(MyVector, Test_push_front) {
    MyVector vec_1(0);
    vec_1.push_front(1); 
    vec_1.push_front(2); 
    vec_1.push_front(3); 

    std::vector<int> actual = vec_1.ConvertToStdVector();
    std::vector<int> expect = {3, 2, 1};
    EXPECT_EQ(actual, expect);

    int actual_size = vec_1.size();
    int expect_size = 3;
    EXPECT_EQ(actual_size, expect_size);

    ErrorCode actual_error = vec_1.get_error();
    ErrorCode expect_error = ErrorCode::kNoError;
    EXPECT_EQ(actual_error, expect_error);

}

TEST(MyVector, Test_pop_front) {
    MyVector vec_1(3);
    vec_1.pop_front(); 
    vec_1.pop_front(); 
    vec_1.pop_front(); 


    std::vector<int> actual = vec_1.ConvertToStdVector();
    std::vector<int> expect = {};
    EXPECT_EQ(actual, expect);

    int actual_size = vec_1.size();
    int expect_size = 0;
    EXPECT_EQ(actual_size, expect_size);


    vec_1.pop_front();
    ErrorCode actual_error = vec_1.get_error();
    ErrorCode expect_error = ErrorCode::kPopFromEmptyVector;
    EXPECT_EQ(actual_error, expect_error);

}


TEST(MyVector, Test_insert) {
    MyVector vec_1;
    vec_1.push_back(1);

    vec_1.insert(3, 0); 
    vec_1.insert(4, 1); 

    std::vector<int> actual = vec_1.ConvertToStdVector();
    std::vector<int> expect = {1, 3, 4};
    EXPECT_EQ(actual, expect);

    int actual_size = vec_1.size();
    int expect_size = 3;
    EXPECT_EQ(actual_size, expect_size);


    vec_1.insert(10, 5);
    ErrorCode actual_error = vec_1.get_error();
    ErrorCode expect_error = ErrorCode::kIndexError;
    EXPECT_EQ(actual_error, expect_error);

}

TEST(MyVector, Test_at) {
    MyVector vec_1;
    vec_1.push_back(1);
    vec_1.insert(3, 0); 
    vec_1.insert(4, 1);     // {1, 3, 4}

    int actual = vec_1.at(0);
    int expect = 1;
    EXPECT_EQ(actual, expect);

    int actual_1 = vec_1.at(10);
    int expect_1 = -1;
    EXPECT_EQ(actual_1, actual_1);


    ErrorCode error = vec_1.get_error();
    ErrorCode expect_error = ErrorCode::kIndexError;
    EXPECT_EQ(error, expect_error);

}

TEST(MyVector, Test_find) {
    MyVector vec_1;
    vec_1.push_back(1);
    vec_1.push_back(1);
    vec_1.insert(3, 0); 
    vec_1.insert(4, 1);     // {1, 3, 4}

    int actual = vec_1.find(1);
    int expect = 0;
    EXPECT_EQ(actual, expect);

    vec_1.find(7);
    ErrorCode error = vec_1.get_error();
    ErrorCode expect_error = ErrorCode::kNotFound;
    EXPECT_EQ(error, expect_error);

}