#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"

// Write several test cases for each function.
//-----------------------------------------------------------------------------
// Make sure you add some test cases to check for nullptr.
TEST(ConcatenateDynamicArrays, test0) {
    CPPLib c;
    int *arr_1 = nullptr;
    int *arr_2 = nullptr;
    
    int *new_arr = c.Concatenate(arr_1, 0, arr_2, 0);
    int *expect_arr = nullptr;
    EXPECT_EQ(new_arr, expect_arr);

}

TEST(ConcatenateDynamicArrays, test1) {
    CPPLib c;
    int size_1 = 2;
    int size_2 = 3;
    int *arr_1 = new int[size_1]{1, 2};
    int *arr_2 = new int[size_2]{2, 3, 4};
    
    int *actual_arr = c.Concatenate(arr_1, size_1, arr_2, size_2);
    int *expect_arr = new int[size_1 + size_2]{1, 2, 2, 3, 4};

    for (int i = 0; i < size_1 + size_2; i++) {
        // std::cout << new_arr[i] << std::endl;
        EXPECT_EQ(*(actual_arr + i), *(expect_arr + i));
    }

    delete [] arr_1;
    delete [] arr_2;
    
}
//-----------------------------------------------------------------------------

TEST(ConcatenateVectors, test2) {

    CPPLib c;
    std::vector<int> vect_1 = {1, 2};
    std::vector<int> vect_2 = {2, 3, 4};
    
    std::vector<int> actual = c.Concatenate(vect_1, vect_2);
    std::vector<int> expect = {1, 2, 2, 3, 4};

    EXPECT_EQ(actual, expect);

}
//-----------------------------------------------------------------------------
