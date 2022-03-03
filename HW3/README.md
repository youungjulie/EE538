
# HW3 EE538
## University of Southern California
## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Deadline: Tuesday, March 1st by 12:00 pm (noon)
- Rubrics:
  
| Question | Points |
| -- | -- |
| 1  | 28 |
| 2  | 15 |
| 3  | 30 |
| 4  | 32 |
| 5  | 30 |


- Total: 135 points. 100 points is considered full credit.


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.

### Q1

Non-parameterized constructor  

- o1 is declared with no initial value,so Non-parameterized constructor is called. 

o1.v_.size(): 0             

- Print out the vector's size using std::cout

Destructor                      

- In this scope, the variable o1 won't be used, so the destructor is called.

---------------------------------------------------------------

### Q2

Non-parameterized constructor  
- o1 is declared with no initial value,so Non-parameterized constructor is called.  

Parameterized constructor   
- o2 is declared with initial value (1, 3),so Non-parameterized constructor is called.  

Copy constructor  
- When o3 = o1, the copy constructor is called, all member values of o1 is copied to o3.  

Destructor  

Destructor

Destructor 

- In this scope, the variables o1, o2, o3 won't be used, so their destructors are called.

---------------------------------------------------------------

### Q3

Non-parameterized constructor  
- o is declared with no initial value,so Non-parameterized constructor is called.  

Copy constructor  
- When calling DoSomthing1(MyClass o) function, o is used as input value. Notice the input value is a copy of original input variable, so the copy constructor is called.  

Something 1.
- The std::cout line in DoSomthing1 is operating.

Destructor  
- The copy of o is no longer used, destructor is called. 

Destructor  
- The variable o is no longer used, destructor is called. 

---------------------------------------------------------------

### Q4

Non-parameterized constructor  
- o is declared with no initial value,so Non-parameterized constructor is called.

Something 2.
- When calling DoSomthing2(MyClass &o) function, this function actually get the address of input variable, so it doesn't create a copy (no need to call Copy constructor). This function can change o directly.
- Somthing 2 is printed in this function.

Destructor
- The variable o is no longer used, destructor is called. 

---------------------------------------------------------------

### Q5

Non-parameterized constructor
- o is declared with no initial value,so Non-parameterized constructor is called.

Something 3. 
- When calling DoSomthing2(MyClass &o) function, this function actually get the address of o, and print the string in the function. 

Destructor
- Destructor of the variable o is called. 

---------------------------------------------------------------

### Q6

Non-parameterized constructor
- o is declared with no initial value,so Non-parameterized constructor is called.

Copy constructor
- Copy constructor is printed since in the DoSomthing4() function, the line `MyClass o2 = o` called the copy constructor. Assigned the value of o to o2. 

Something 4.
- `std::cout` is called in the DoSomthing4() function

Destructor
- Destructor of the copy variable

Destructor
- Destructor of the o variable

---------------------------------------------------------------

### Q7

Parameterized constructor
- The first input value of pair is `MyClass(1, 2)` which called the Parameterized constructor.

Copy constructor
- Actually, once the first input is created by `MyClass(1, 2)`, a copy of `MyClass(1, 2)` is created and passed as the actual input variable of the pair. Thus, the copy constructor is called. 

Destructor
- Since the original variable (`MyClass(1, 2)`) is not needed, the destructor of it is called.  

p1.first.v_.size(): 0
- p1.first is the object `MyClass(1, 2)` with two `int` 1 and 2, but it doesn't modify the public variable v_, so the size of v_ is still 0. 

p1.second: 0
- The second variable of the pair is 0 as initialized  
- (`std::pair<MyClass, int> p1 = {MyClass(1, 2), 0};`)

Copy constructor
- `std::pair<MyClass, int> p2 = p1`: This line implies the copy constructor is called, since p1 is a copy of p2. 

p2.first.v_.size(): 0
- Since it's a deep copy, every member variable of p2 is the same as p1, so `p2.first == p1.first`. Their vectors' size is the same as 0. 

p2.second: 0
- Since it's a deep copy, every member variable of p2 is the same as p1, so `p2.second == p1.second` = 0.

Destructor  
- This is the destructor of the copy variable (p2)

Destructor
- This is the destructor of the copy variable (MyClass(1, 2))

---------------------------------------------------------------

### Q8

Parameterized constructor
- `MyClass(1, 2)` called the Parameterized constructor

Copy constructor
- Since the pair's input is a copy of original input, MyClass()'s copy constructor is called. 

Destructor
- The orginal `MyClass(1, 2)` is not needed, its destructor is called. 

Something 2.
- First time iteration when p.second == 0. In this for loop, 0 is pushed back to the v_ variable of p.first. 

Something 2.
- Second time iteration when p.second == 1. In this for loop, 1 is pushed back to the v_ variable of p.first. 

Something 2.
- Second time iteration when p.second == 2. In this for loop, 2 is pushed back to the v_ variable of p.first. 

Destructor
- When the copy of `MyClass(1, 2)` is used, the program calls the destructor. 

---------------------------------------------------------------

### Q9

Parameterized constructor
- The line `o = new MyClass(1, 2)`called the Parameterized constructor with parameter 1 and 2. 
- The variable o is the address the pointer pointing to.
- The destructor is not called since the o is a dynamic variable. To release the memory space it using, delete [] should be called. After that the destructor will be called.  

---------------------------------------------------------------

### Q10

Parameterized constructor
- The line `o = new MyClass(1, 2)`called the Parameterized constructor with parameter 1 and 2. 

Destructor
- Since delete [] is called, the destructor of the variable is called. 

---------------------------------------------------------------

### Q11

Non-parameterized constructor
- `MyClass()` constructor

Copy constructor
- `MyClass()` 's copy constructor

Parameterized constructor
- `MyClass(1, 2)` constructor

Copy constructor
- `MyClass(1, 2)` 's copy constructor

Parameterized constructor
- `MyClass(3, 4)` constructor

Copy constructor
- `MyClass(3, 4)` 's copy constructor

#### **We are in the loop `auto e : my_map`**

- e is every element in the map. When iterating through the map, every element of the my_map is copied to the variable my_map in the loop. 

Copy constructor
- The first element of the map, `MyClass()` is copied.

Copy constructor
- The second element of the map, `MyClass(1, 2)` is copied.

Copy constructor
- The third element of the map, `MyClass(3, 4)` is copied.

Destructor

Destructor

Destructor
- The first 3 destructor is for the 3 variables: when creating the map, 3 non-copy constructors are used. 

Destructor

Destructor

Destructor
- These 3 destructor is for the 3 variables: when iterating through the map, 3 copy constructors are used. 

Copy constructor
- 1st iteration: `e = {0, MyClass()}`
- When insert the `e.first` element, we need to make a copy of e and get its `first`
- `MyClass()` is copied again.

Destructor
- The copy of `e = {0, MyClass()}` for current e is no longer needed, the copy of `MyClass()` is destructed. 

Copy constructor
- 2nd iteration: `e = {3, MyClass(1, 2)}`
- When insert the `e.first` element, we need to make a copy of e and get its `first`
- `MyClass(1, 2)` is copied again.

Destructor
- The copy of `e = {3, MyClass(1, 2)}` for current e is no longer needed, the copy of `MyClass(1, 2)` is destructed. 

Copy constructor
- 3nd iteration: `e = {5, MyClass(3, 4)}`
- When insert the `e.first` element, we need to make a copy of e and get its `first`
- `MyClass(3, 4)` is copied again.

Destructor
- The copy of `e = {5, MyClass(3, 4)}` for current e is no longer needed, the copy of `MyClass(3, 4)` is destructed. 

Destructor

Destructor

Destructor
- After iterating through the map, the `my_map` copy is no longer needed, so all elements in it are destructed. 

---------------------------------------------------------------
 
### Q12

Non-parameterized constructor
- `MyClass()` constructor

Copy constructor
- `MyClass()` 's copy constructor

Parameterized constructor
- `MyClass(1, 2)` constructor

Copy constructor
- `MyClass(1, 2)` 's copy constructor

Parameterized constructor
- `MyClass(3, 4)` constructor

Copy constructor
- `MyClass(3, 4)` 's copy constructor

#### **We are in the loop `auto e : my_map`**

- e is every element in the map. When iterating through the map, every element of the my_map is copied to the variable my_map in the loop. 

Copy constructor
- The first element of the map, `MyClass()` is copied.

Copy constructor
- The second element of the map, `MyClass(1, 2)` is copied.

Copy constructor
- The third element of the map, `MyClass(3, 4)` is copied.

Destructor

Destructor

Destructor
- The first 3 destructor is for the 3 variables: when creating the `my_map`, 3 non-copy constructors are used. 

Destructor

Destructor

Destructor
- These 3 destructor is for the 3 variables: when creating the `my_map`, 3 copy constructors are used. 

Destructor

Destructor

Destructor
- These 3 destructor is for the 3 variables: when iterating through the `my_map`, 3 copy constructors are used. Now after iteration, the `my_map` is no longer useful and can be destructed.

**The difference from Q11 is: since we are using the address of the input variable e in the for loop, we don't need to make another copy of e.**

---------------------------------------------------------------

### Q13

Parameterized constructor
- The line `o = new MyClass(1, 2)`called the Parameterized constructor with parameter 1 and 2. 

Destructor
- Since delete [] is called, the destructor of the variable is called. 

---------------------------------------------------------------

### Q14

Parameterized constructor
- The line `MyClass o(100000000)`called the Parameterized constructor with parameter 100000000. 

Operation took: 1343 milliseconds
- The operation time of creating a `MyClass o(100000000)` object is 1343 milliseconds.
- This process is to append 100000000 numbers to the o.v_ variable. 

#### **When i = 0**

Copy constructor
- The code `MyClass o2 = o` used the copy constructor

Copy constructor
- `DoSomthing1(o2)` this function's input value is a copy of o2, so the Copy constructor is called.

Something 1.
- Something 1 is printed in the function `DoSomthing1()`

Destructor
- After the DoSomthing function, the o2's copy variable is no longer needed, so the destructor is called. 

o2.v_.size(): 100000000
- o2 is the copy of o, so it has the same size as o, which is 100000000. 

Destructor
- After this iteration when i = 0, the o2's is no longer needed, so the destructor is called. 

#### **When i = 1**

Copy constructor
- The code `MyClass o2 = o` used the copy constructor

Copy constructor
- `DoSomthing1(o2)` this function's input value is a copy of o2, so the Copy constructor is called.

Something 1.
- Something 1 is printed in the function `DoSomthing1()`

Destructor
- After the DoSomthing function, the o2's copy variable is no longer needed, so the destructor is called. 

o2.v_.size(): 100000000
- o2 is the copy of o, so it has the same size as o, which is 100000000. 

Destructor
- After this iteration when i = 0, the o2's is no longer needed, so the destructor is called. 

Operation took: 670 milliseconds
- The operating time is the time takes to operate this for loop. 

Destructor
- The variable o is no longer needed, so it's destructed.

---------------------------------------------------------------

### Q15

Parameterized constructor
- The line `MyClass o(100000000)`called the Parameterized constructor with parameter 100000000. 

Operation took: 1221 milliseconds
- The operation time of creating a `MyClass o(100000000)` object is 1221 milliseconds.
- This process is to append 100000000 numbers to the o.v_ variable. 

#### **When i = 0**

Copy constructor
- The code `MyClass o2 = o` used the copy constructor

Something 2.
- `DoSomthing1(o2)` this function's input value is address of o2, so no constructor is called.
- Something 2 is printed in the function `DoSomthing2()`

o2.v_.size(): 100000000
- o2 is the copy of o, so it has the same size as o, which is 100000000. 

Destructor
- After this iteration when i = 0, the o2's is no longer needed, so the destructor is called.

#### **When i = 1**

Copy constructor
- The code `MyClass o2 = o` used the copy constructor

Something 2.
- `DoSomthing1(o2)` this function's input value is address of o2, so no constructor is called.
- Something 2 is printed in the function `DoSomthing2()`

o2.v_.size(): 100000000
- o2 is the copy of o, so it has the same size as o, which is 100000000. 

Destructor
- After this iteration when i = 1, the o2's is no longer needed, so the destructor is called.

Operation took: 290 milliseconds
- During this time of for loop, the operation time is much less than Q14, since it refers the address of input value instead of making a copy, so it saves much time. 

Destructor
- The variable o is no longer needed, so it's destructed.

---------------------------------------------------------------

### Q16

#### **`std::vector<MyClass> my_vector`**

Parameterized constructor   `MyClass(10000000)`

Parameterized constructor   `MyClass(20000000)`

Parameterized constructor   `MyClass(30000000)`

Parameterized constructor   `MyClass(40000000)`

Parameterized constructor   `MyClass(50000000)`

Parameterized constructor   `MyClass(60000000)`

Parameterized constructor   `MyClass(70000000)`
- When creating the my_vector, it creates 7 MyClass(int) variables with parameter, so the Parameterized constructor is called 7 time. 

Copy constructor

Copy constructor

Copy constructor

Copy constructor

Copy constructor

Copy constructor

Copy constructor
- Each time when it creates a MyClass(int) variable, this variable is passed into the `vec = {}` operator. In fact, the variable passed in is the copy of the original MyClass object. Thus the copy constructor is called 7 times. 

Destructor

Destructor

Destructor

Destructor

Destructor

Destructor

Destructor
- When finished the creating vector process, these original MyClass(int) variable is useless, so we destruct them by calling the destructors.  

Operation took: 4167 milliseconds
- The creating vector process takes 4167 milliseconds, it includes all constructor, copy constructor and destructor process. 


#### **The first iteration of the first for loop, case `e = MyClass(10000000)`**

Copy constructor
- Every time the `for (auto e : my_vector)` runs, a copy constructor is created. It copies the current value in `my_vector` to e, so e calls a copy constructor. 

e.v_.size(): 10000000
- This line is printed in the for loop

Destructor
- When finished one iteration, the e generated in the current loop is no longer needed, so its destructor is called.  

#### **Same process for the iteration below**

Copy constructor

e.v_.size(): 20000000

Destructor


Copy constructor

e.v_.size(): 30000000

Destructor


Copy constructor

e.v_.size(): 40000000

Destructor


Copy constructor

e.v_.size(): 50000000

Destructor


Copy constructor

e.v_.size(): 60000000

Destructor


Copy constructor

e.v_.size(): 70000000

Destructor


Operation took: 474 milliseconds
- This operation time measures the 7 times to print all MyClass() variables' size. During each time, the copy constructor and the destructor is called. 


#### **The first iteration of the second for loop, case `e = MyClass(10000000)`**

e.v_.size(): 10000000
- In this for loop, e is created using the reference of variables in my_vector, so there is no constructor or destructor called during this process. 
- The only output is the line printed the size of vector of e (`MyClass()` variable).

#### **Same process for iteration below**

e.v_.size(): 20000000

e.v_.size(): 30000000

e.v_.size(): 40000000

e.v_.size(): 50000000

e.v_.size(): 60000000

e.v_.size(): 70000000


Operation took: 0 milliseconds
- The second for loop takes 0 milliseconds, it's a huge reduce since we use reference instead of copy constructor. 


Destructor

Destructor

Destructor

Destructor

Destructor

Destructor

Destructor
- Once finished all for loop, the 7 MyClass(int ) objects are no longer needed, so their destructor is called on by one. 

---------------------------------------------------------------

Done!
