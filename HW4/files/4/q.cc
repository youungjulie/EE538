#include "q.h"

#include <iostream>
#include <vector>
// Implement each function of `q.h` here.

// 1. Implement knapSack01NoDynamicProgramming:
int knapSack01NoDynamicProgramming(const std::vector<int> &weights,
                                   const std::vector<int> &values, int w) {
    int current_index = weights.size() - 1;
    return knapSack01NoDynamicProgramming_Helper(weights, values, w, current_index);
}

// 2. Define knapSack01NoDynamicProgramming_Helper and implement it in the .cc
// file. This function has takes similar arguments like
// knapSack01NoDynamicProgramming with some extra helper parameters:
int knapSack01NoDynamicProgramming_Helper(const std::vector<int> &weights,
                                          const std::vector<int> &values, int w,
                                          int i) {
    // i is the ith item
    if (i == -1 || w == 0) {return 0;}

    // if current weight cannot include the current item's weight
    if (w - weights[i] < 0) {
        return knapSack01NoDynamicProgramming_Helper(weights, values, w, i-1);
    }

    return std::max(knapSack01NoDynamicProgramming_Helper(weights, values, w - weights[i], i-1) + values[i], 
                    knapSack01NoDynamicProgramming_Helper(weights, values, w, i-1));
}


//-----------------------------------------------------------------------------
// 3. Implement knapSack01Memo:
// The knapSack01Memo function itself doesn't use a memo. It's just a wrapper
// around knapSack01Memo_Helper.
int knapSack01Memo(const std::vector<int> &weights,
                   const std::vector<int> &values, int w) {
    int row = weights.size();
    int col = w;
    int current_index = weights.size() - 1;

    std::vector<std::vector<int>> memo(row, std::vector<int> (col, 0));
    
    int result = knapSack01Memo_Helper(weights, values, w, current_index, memo);

    return result;
}

// 4. Implement knapSack01Memo_Helper. This function has takes similar arguments
// like knapSack01Memo with some extra helper parameters such as i and memo,
// which is a two-dimensional vector:
int knapSack01Memo_Helper(const std::vector<int> &weights,
                          const std::vector<int> &values, int w, int i,
                          std::vector<std::vector<int>> &memo) {
    if (i == -1 || w == 0) return 0;

    if (memo[i][w] > 0) {return memo[i][w];}

    if (weights[i] > w) {
        memo[i][w] = knapSack01Memo_Helper(weights, values, w, i - 1, memo);
        return memo[i][w];
    }


    memo[i][w] = std::max(knapSack01Memo_Helper(weights, values, w - weights[i], i - 1, memo) + weights[i], 
                          knapSack01Memo_Helper(weights, values, w, i - 1, memo));

    return memo[i][w];

}


//-----------------------------------------------------------------------------
// 5. Implement knapSack01Tablulation. Use a two-dimensional vector for the
// table.
int knapSack01Tablulation(const std::vector<int> &weights,
                          const std::vector<int> &values, int w) {
    std::vector<std::vector<int>> d(values.size() + 1, std::vector<int> (w + 1, 0));   
    for (int i = 0; i <= weights.size(); i++) {
        for (int current_weight = 0; current_weight <= w; current_weight++) {
            if (i == 0 || current_weight == 0) {
                d[i][current_weight] = 0;
            }

            else if (weights[i - 1] > current_weight) {
                d[i][current_weight] = d[i-1][current_weight];
            }

            else {
                d[i][current_weight] = std::max(values[i-1] + d[i-1][current_weight - weights[i-1]], d[i-1][current_weight]);
            }
        }
    }      
    return d[values.size()][w];
}