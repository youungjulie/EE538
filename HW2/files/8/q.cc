#include <iostream>
#include <vector>
#include <set>

#include "q.h"

// Write a function that takes a vector of positive integers as input. The
// output is the same vector where all duplicates are removed. Note that the
// output is the same vector means the function's return type should be void and
// do the modifications on the input vector. Example: before: v=[1, 2, 2, 4],
// after : v=[1, 2, 4] Solve this for the following cases: You cannot use
// std::set
void CPPLib::UniqueVectorNotBySet(std::vector<int> &input) {
    std::vector<int> result = {};
    if (input.size() >= 1) {
        result.push_back(input[0]);
        for (auto n : input) {
            int count = 0;
            for (auto m : result) {
                if (n == m) {
                    count+=1; 
                }
            }
            if (count == 0) {
                result.push_back(n);
            }
        }
    }
    input = result; 
    return; 
}

// You can use std::set
void CPPLib::UniqueVectorBySet(std::vector<int> &input) {
    std::set<int> res_set(input.begin(), input.end());
    std::vector<int> result_vec(res_set.begin(), res_set.end());
    input = result_vec;
    return; 
}

// Write a function that takes two vectors v1 and v2 and returns a new vector
// that is the intersection of the values in v1 and v2. All the values in return
// vector should be unique.
// Example: input: v1={1, 2, 2, 3}, v2={3, 4, 4, 5},
// output = {1, 2, 3, 4, 5}
std::vector<int> CPPLib::IntersectVectors(std::vector<int> &input1,
                                          std::vector<int> &input2) {
    std::vector<int> result = {};
    for (auto n : input1) {
        result.push_back(n);
    }
    for (auto m : input2) {
        result.push_back(m);
    }

    CPPLib::UniqueVectorBySet(result);
    return result;
    }
