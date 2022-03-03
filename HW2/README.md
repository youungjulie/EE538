
# HW2 EE538
## University of Southern California
## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Deadline: Tuesday, Feburary 15th by 12:00 pm (noon)
- Rubrics:
  
| Question | Points |
| -- | -- |
| 1  | 10 |
| 2  | 25 |
| 3  | 20 |
| 4  | 10 |
| 5  | 20 |
| 6  | 25 |
| 7  | 10 |
| 6  | 15 |

- Total: 135 points. 100 points is considered full credit.

### Question 5: 
Concatenate two dynamic arrays.

**Question 1: Why did we have to provide size_1, size_2 as an input?**
- we don't know the size of these two dynamic arrays, In order to generate a new array, we need to know the size of the new array at the compiling time.

**Question 2: How can we know the size of the output?**
- The size of the output is the sum of the size of two input arrays.We can know the size of output, when we get the parameter size_1 and size_2.


Concatenate two dynamic vectors.

**Question 1: Why didn't we provide the sizes?**
- vector stores the size, vector.size(), so we can get the size through the build-in function instead of providing it. 

**Question 2: We have two functions with the name of Concatenate. Is this ok?**
- It's overloading function. Depending on the type of input given to the function, the compiler will decide which function to use. Thus it's fine to have two functions with same name. 


### Question 6: 
**Q1**
- Cannot call elements[i], need to define length of vector at the beginning
- The element variable cannot cin in this way. We need to use cin first to get the value of element, and then push it back to the vector elements

**Q2**
- The pointer doesn't have memory location, so it doesn't get the space to store the input value. We need to use `new int` to allocate memory for this pointer. 

**Q3**
- This question is correct

**Q4**
- The `a++` and `b++` code are undefined behaviour. The a and b address will change to other address, and we might change the original value at that place. 
- We can change the `a++` and `b++` to `(*a)++` and `(*b)++`, so we increment the value at the place of a and b. 

**Q5**
- This is an infinite loop (i = i - 1)
- Change to i = i + 1


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.
