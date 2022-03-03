
# HW1 EE538 - Computing Principles for Electrical Engineers

- Please clone the repository, edit [README.md](README.md) to answer the questions, and fill up functions to finish the homework.
- For non-coding questions, fill out the answers below each question. Please write your answer there.
- For coding questions, please make sure that your code can run ```bazel run/test```. In this homework, you will need to fill up [cpplib.cc](src/lib/cpplib.cc) and tests in [tests](tests). **Do Not change or modify any given function names and input or output formats in both [cpplib.cc](src/lib/cpplib.cc) and tests in [tests](tests). Unexpected changes will result in **zero** credit.**
- For coding questions, there is a black box test for each question. All points are only based on passing the test cases or not (i.e. we don't grade your work by your source code). So, try to do comprehensive testing before your final submission.
- For submission, please push your answers to Github before the deadline.
- Deadline: **Tuesday, Feb 1st by 12 pm**
- Total: 130 points. 100 points is considered full credit.

## Question 1 (10 Points. Easy)

Create an account on GitHub and Stack Overflow and paste the link to your profile.

GitHub profile link: https://github.com/youungjulie

Stack Overflow profile link: https://stackoverflow.com/users/18022334/longhao-yang

## Question 2 (20 Points. Medium)

Write a function called **FindAverage**, which returns the average of the inputs of a vector of integers. Use the steps the following steps:
1. Clearly specify input and output.
2. Write some example input and outputs. Try to cover corner cases. Feel free to make reasonable assumptions for the corner cases.
3. Implement your algorithm.
4. Write several unit tests that cover all corner cases, and test your algorithm using bazel.
You will need to only submit your algorithm implementation and the unit tests.

Answer: 
1. input: vector of integer
    output: double/float
2. corner case:
    1. if the input vector is empty, we return -1
    2. normally sample input: {1, 2, 4, 5} output: 3
    3. normally sample input: {1, 2, 3, 5} output: 2.75 (double output)

3. Implementation
```cpp
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
```
4. test case is in tests/q2_student_test.cc file


## Question 3 (20 Points. Medium)

Compute the worst case run-time complexity of the below functions. Please provide both the computation process and final result for full credit.

```cpp
void Example1(int n) {
   int i = 1;
   while (i < n) {
       i *= 2;
   }
}
```

Answer: 
The constant run time is indicated above. 
The while loop runs logn times. 
The worst case is T(n)(log2n + 3) = O(logn)

```cpp
void Example2(int n) {
   int count = 0;
   for (int i = 1; i <= n; i = i * 2) {
       for (int j = 1; j <= n; j++) {
           for (int k = 1; k <= n; k = k * 3) {
               count++;
           }
       }
   }
}
```

Answer:
First loop: O(log n)
Second loop: O(n)
Third loop: O(log n)
The worst case is O(logn * n * logn)

```cpp
void Example3(int n) {
   int count = 0;
   for (int i = 0; i < n; i++)
       for (int j = i; j < i*i*i; j++)
            std::cout<<"*";
}
```

Hint: Note the ```j < i*i*i``` in the inner loop and compute the cube sequence to get the final result.

Answer:
T(n) = 0 + 1 - 1 + 8 - 2 + (4^3 - 4) + ... + (n^3 - n)
     = (1 + 2^3 + 4^3 + ... + n^3) - (1 + 2 + ... + n)
     = n^2(n+1)^2 / 4 - ((1 + n)n/2)
T(n) = O(n^4)

```cpp
int Example4(int n) {
   int count = 0;
   for (int i = 1; i < n; i *= 3) {
      for (int j = n; j > 0; j /= 3) {
          for (int k = 0; k < j; k++) {
              count += 1;
          }
      }
   }
   return count;
}
```

Hint: Note the ```i /= 3``` in the outer loop and compute the geometric sequence to get the final result.

Answer:
First loop: log n 
Second loop and Third loop: n + n/3 + n/9 + ... + 1 (log n)

The worst case is O(logn * logn)

## Question 4 (10 Points. Easy)

What does it mean when we say that the **Heap Sort (HS)** algorithm is asymptotically more efficient than the **Bubble Sort (BS)** algorithm **assuming the input is randomly ordered**? Support your choice with an explanation.


1. HS will always be a better choice for small size inputs
2. BS will always be a better choice for small size inputs
3. HS will always be a better choice for large size inputs
4. BS will always be a better choice for large size inputs
5. HS will always be a better choice for inputs of any size
6. BS will always be a better choice for inputs of any size


Answer:
#### Correct: 
3. HS will always be a better choice for large size inputs
#### Explain: 
Regarding the run time complexity, the HS's run time complexity is O(n*logn), and the BS's run time complexity of O(n^2). 
For infinite large input n, the run time complexity of HS is better than BS. 
But we need to keep in mind that HS is not a stable sorting algo, while BS is stable.  

## Question 5 (15 Points. Easy)

Write a simple function ```std::string CPPLib::PrintIntro()``` in [cpplib.cc](src/lib/cpplib.cc) to print your name, email, and any information about you that you want (e.g. your major, your expertise, your interests, etc) and write a test using GTest for your function in [tests/q5_student_test.cc](tests/q5_student_test.cc). We will run your code and see your printout!

Please create your test cases and run the following command to verify the functionality of your program.

```bash
bazel test tests:q5_student_test
```

## Question 6 (25 Points. Medium)

 Write a function ```std::vector<int> CPPLib::Flatten3DVector(const std::vector< std::vector< std::vector<int> > > &input)``` in [cpplib.cc](src/lib/cpplib.cc) to flatten a 3D vector into a 1D vector.

Example:\
Input: inputs = [[[1, 2], [3, 4]], [[5], [6], []], [[7, 8]]].\
Output: result = [1, 2, 3, 4, 5, 6, 7, 8].

Write several tests using GTest for your function in [tests/q6_student_test.cc](tests/q6_student_test.cc).\
(Hint: include cases with empty vectors)

Please create your test cases and run the following command to verify the functionality of your program.
```
bazel test tests:q6_student_test
```
What is the worst case runtime complexity of your implementation?

Answer:
The worst case rum time complexity is O(n^3)

## Question 7 (30 Points. Medium)

Write a function ```int CPPLib::climbStairs(int n)``` in [cpplib.cc](src/lib/cpplib.cc) using recursion to find how many distinct ways you can climb to the top. Your function should accept positive numbers less than 45 and return the number of ways. Further, write several tests using GTest for your function in [tests/q7_student_test.cc](tests/q7_student_test.cc) and compute the time complexity of your implementation.

*Rules of the climb stairs*\
You are climbing a staircase. Each time you can either climb 1 or 2 steps. It takes n steps to reach the top.

If there are 0 stairs, there is 0 way to the top. For negative input, please return -1.

For example, if the stairs number is 4(n = 4), it should have 5 ways to the top.\
1 + 1 + 1 + 1\
1 + 1 + 2\
1 + 2 + 1\
2 + 1 + 1\
2 + 2

Please create your test cases and run the following command to verify the functionality of your program.

```bash
bazel test tests:q7_student_test
```
**Hint**: Try to write a recursive relationship.
What is the complexity of your implementation?

Answer:
O(n)