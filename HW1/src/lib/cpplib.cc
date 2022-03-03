#include "cpplib.h"
#include "limits"

std::string CPPLib::PrintHelloWorld() { return "**** Hello World ****"; }

// NOTE: write your own function declaration q2 here
double CPPLib::FindAverage(std::vector<int> arr) {
    double sum = 0;
    double average = 0; 

    if (arr.size() == 0) {
        return -1; 
    }

    else {
        for (auto n : arr) {
            sum += n;
        }
        average = sum/arr.size(); 
    }

    return average; 
}


// Question 5 Print your self-introduction
std::string CPPLib::PrintIntro() {
    // Please fill up this function.
    return "Hello all, I'm Longhao Yang. \nMy email is longhaoy@usc.edu. \nI'm majoring in Machine Learning and Data Science under ECE department. \n"; 
}

// Question 6
std::vector<int> CPPLib::Flatten3DVector(const std::vector< std::vector< std::vector<int> > > &input){
    // Please fill up this function.
    std::vector<int> res;
    if (input.size() == 0){
        return {};
    }

    for (auto vect_1: input) {
        if (vect_1.size() == 0){
            continue;
        }
        else {
            for (auto vect_2: vect_1) {
                if (vect_2.size() == 0){
                    continue;
                }
                else {
                    for (auto i : vect_2){
                        res.push_back(i); 
                    }
                }
            }
        }
    }


    return res;
}

// Question 7 Climbing Stairs
int CPPLib::climbStairs(int n){
    // Please fill up this function.
    int res = 0;
    if (n == 0) {return 0;}
    else if (n == 1) {return 1;}
    else if (n == 2) {return 2;}
    else if (n < 0) {
        return -1;
    }
    else {
        res = climbStairs(n-1) + climbStairs(n-2);
    }
    return res;
}

