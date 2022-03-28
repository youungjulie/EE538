#include "q.h"

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <iterator>
#include <limits>

// Implement each function of `q.h` here.

// Your implementation should have a worst case runtime complexity of O(n) and
// memory complexity of O(1).
int Fibonacci(int n) {
    if (n == 0 || n == 1) return 1;
    int prev_1 = 1;
    int prev_2 = 1;
    for (int i = 0; i < n - 2; i++) {
        int temp = prev_1;
        prev_1 += prev_2;
        prev_2 = temp;
    }
    return prev_1;
}

// Implement a function that calculates the minimum number and use memoization
// but with a twist: you are only allowed to use an std::list for the memo (Do
// not use map, unordered_map, set, vector, or array).

// CoinChangeMemo is not a recursive function, but it is a wrapper around
// CoinChangeMemo_Helper that is recursive. Use std::list<int> for memo.
int CoinChangeMemo(std::vector<int>& coins, int amount) {
    // initialize the memo table, index is amount, value is min number of coins to achieve the amount 

    std::list<int> memoization;
    memoization.push_back(0);
    for (int i = 1; i <= amount; i ++) {
        memoization.push_back(INT32_MAX - 1);
    }
    
    return CoinChangeMemo_Helper(coins, amount, memoization);
}

int CoinChangeMemo_Helper(std::vector<int>& coins, int amount,
                           std::list<int>& memo) {
    for (auto coin : coins) {
        int remain = amount - coin;
        if (remain >=0) {
            auto iter = std::next(memo.begin(), amount); 
            int minimum = std::min(*(std::next(memo.begin(), amount)), *(std::next(memo.begin(), remain))+1);
            iter = memo.erase(iter);
            memo.insert(iter, minimum);
            CoinChangeMemo_Helper(coins, remain, memo);
        }
        
    }
    return *(std::next(memo.begin(), amount));
}

//-----------------------------------------------------------------------------
// Implement a function that calculates the minimum number and use tabulation
// but with a twist: you are only allowed to use an std::list for the table
// inside this function (Do not use map, unordered_map, set, vector, or array):
int CoinChangeTabulation(std::vector<int>& coins, int amount) {
    // Create a list with index = amount
    // value = minmum number of coin 
    std::list<int> table;
    table.push_back(0);
    for (int i = 1; i <= amount; i ++) {
        table.push_back(INT32_MAX - 1);
    }

    // Update each amount
    for (int i = 1; i <= amount; i++) {
        auto iter = table.begin();
        std::advance(iter, i);

        // For each amount, find minimum number of coins
        for (auto coin : coins) {

            auto iter_2 = table.begin();

            if (i - coin >= 0) {
                std::advance(iter_2, i - coin);

                int val_amount = *iter;
                int val_remain = *iter_2;
                int minimum = std::min(val_amount, val_remain + 1);

                iter = table.erase(iter);
                table.insert(iter, minimum);

                // move iterator to the original place
                --iter;
            }
        }
    }
    
    auto final_iter = table.begin();
    std::advance(final_iter, amount);

    // Print out the table
    std::cout << "***********" << std::endl;
    for (int m = 0; m <= amount ; ++m) {
        auto iter_3 = table.begin();
        std::advance(iter_3, m);
        std::cout << "Amount: " << m << "\tCoins: ";
        std::cout << *iter_3 << std::endl; 
    }
    std::cout << "***********" << std::endl;

    return *final_iter > amount ? -1 : *final_iter;
}

// int main() {
//     std::vector<int> coins = {8, 3, 1, 2};
//     int amount = 3;
//     int result = CoinChangeTabulation(coins, amount);
//     std::cout << "The result is " << result << std::endl; 
// }