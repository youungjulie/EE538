#include "q.h"

#include <iostream>
#include <vector>

// Concatenate two dynamic arrays.
// Example:
// array_1 = {1, 2}, size_1 = 2
// array_2 = {2, 3, 4}, size_12 = 3
// Output: {1, 2, 2, 3, 4}.
// Question 1: Why did we have to proved size_1, size_2 as an input?
// Question 2: How can we know the size of the output?
int* CPPLib::Concatenate(int* array_1, int size_1, int* array_2, int size_2) { 
    if (size_1 + size_2 != 0) {
        int *result = new int[size_1 + size_2];

        for (int i = 0; i < size_1; i++) {
            result[i] = *(array_1 + i);
        }
        for (int j = 0; j < size_2; j++) {
            result[size_1 + j] = *(array_2 + j);
        }

        for (int k = 0; k < size_1 + size_2; k++) {
            std::cout << result[k] << std::endl;
        }
        return result;
    }

    return nullptr;
}
//-----------------------------------------------------------------------------
// Concatenate two dynamic vectors.
// Example:
// vector_1 = {1, 2}
// vector_2 = {2, 3, 4}
// Output: {1, 2, 2, 3, 4}.
// Question 1: Why didn't we provide the sizes?
// Question 2: We have two functions with the name of Concatenate. Is this ok?
std::vector<int> CPPLib::Concatenate(std::vector<int>& vector_1,
                                     std::vector<int>& vector_2) {
    std::size_t size_1 = vector_1.size();
    std::size_t size_2 = vector_2.size();

    std::vector<int> result;

    for (std::size_t n = 0; n < size_1; n++) {
        result.push_back(vector_1[n]);
    }

    for (std::size_t m = 0; m < size_2; m++) {
        result.push_back(vector_2[m]);
    }

    return result;
}
//-----------------------------------------------------------------------------
