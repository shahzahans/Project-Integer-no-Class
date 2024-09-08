[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/RjLVXri_)
# Integer Set Operations

In this assignment you are expected to implement functions representing several set operations.

## Goal
Implement C++ functions tha represent some integer set operations. Once the functions are _correctly_ implemented then you will pass the 61 tests that are given to you in the main file.

This lab will help you practice the following topics:
* Working with tests
* Working with multiple source code files
* Working with arrays

## The Set Operations
The operations that you will need to implement are the following:
- Initialization
- Add an element
- Belongs
- Intersection
- Union
- Complement
- Write to a stream
- Read from a stream
- Get the number of elements in the set

Here is the list of the functions you need to implement, each one of them corresponds to one of the operations listed above.

```c++
/**
 * Initializes the set represented by (set, size). It will assign false to each of the size elements
 * of the array set.
 * @param set the array of bool that represents whether a number is part of the set or not.
 * @param size the number of elements of the array
 */
void InitializeSet(bool set[], size_t size);


/**
 * Adds an element to the array. Effectively is like A + {element} where A is an existing set.
 * The set is represented by (set, size).
 * @param set the array of bool that represents whether a number is part of the set or not.
 * @param size the number of elements of the array
 * @param element the number that is going to be added to the set
 * @return true if the element was added (element < size), false otherwise
 */
bool AddElement(bool set[], size_t size, size_t element);


/**
 * Checks whether the element belongs to the set or not.
 * @param set the array of bool that represents whether a number is part of the set or not.
 * @param size the number of elements of the array
 * @param element the element to be tested
 * @return true if element is in the set (belongs to), false otherwise
 */
bool Belongs(const bool set[], size_t size, size_t element);


/**
 * Performs the intersection operation between two sets (setLHS, sizeLHS) and (setRHS, sizeRHS). LHS for
 * the Left-hand Side, and RHS for the Right-Hand Side of the operation. This operation returns true
 * when the intersection was possible, and false otherwise. The intersection is not possible if setLHS and setRHS
 * have an element that cannot be represented by the resulting set.
 * a10 = {0, 1, 8} b10 = {0, 8, 9} r5
 * When intersecting a10 with b10 the result would be {0, 8},  the element {8} cannot be represented by r5 (only
 * five available positions)
 * c10 = {0, 4, 7, 9} d10 = {4} r5
 * This intersection IS possible, the result would be {4} and that perfectly "fits" in r5.
 * @param setLHS the set of the Left Hand Side of the Intersection operation
 * @param sizeLHS the number of possible elements the Left Hand Side set can have
 * @param setRHS the set of the Right Hand Side of the Intersection operation
 * @param sizeRHS the number of possible elements the Right Hand Side set can have
 * @param set the resulting set from the Intersection lf setLHS and setRHS
 * @param size the number of elements of the resulting array
 * @return true if the intersection was successful, false otherwise.
 */
bool Intersection(const bool setLHS[], size_t sizeLHS, const bool setRHS[], size_t sizeRHS, bool set[], size_t size);


/**
 * Performs the union operation between two sets (setLHS, sizeLHS) and (setRHS, sizeRHS). LHS for
 * the Left Hand Side, and RHS for the Right Hand Side of the operation. This operation returns true
 * when the union was possible, and false otherwise. The union is not possible if setLHS or setRHS
 * have an element that cannot be represented by the resulting set.
 * a10 = {0, 1, 8} b5 = {0, 1, 3} r5
 * When union a10 with b5 the result would be {0, 1, 3, 8},  the element {8} cannot be represented by r5 (only
 * five available positions)
 * c10 = {0, 3} d10 = {4} r5
 * This union IS possible, the result would be {0, 3, 4} and that perfectly "fits" in r5.
 * @param setLHS the set of the Left Hand Side of the Union operation
 * @param sizeLHS the number of possible elements the Left Hand Side set can have
 * @param setRHS the set of the Right Hand Side of the Union operation
 * @param sizeRHS the number of possible elements the Right Hand Side set can have
 * @param set the resulting set from the Union lf setLHS and setRHS
 * @param size the number of elements of the resulting array
 * @return true if the union was successful, false otherwise.
 */
bool Union(const bool setLHS[], size_t sizeLHS, const bool setRHS[], size_t sizeRHS, bool set[], size_t size);


/**
 * Performs the complement operation on the given set.
 * For example if a set is bool a[5] = {true, false, false, false, true} 
 * this represents the set a5 = {0, 4} if the complement is applied to a5
 * then the set will become a5 = {1, 2, 3}
 * @param set the array of bool that represents whether a number is part of the set or not.
 * @param size the number of elements of the array
 */
void Complement(bool set[], size_t size);


/**
 * Compares two sets.
 * @param setLHS the set of the Left Hand Side of the Equals operation
 * @param sizeLHS the number of possible elements the Left Hand Side set can have
 * @param setRHS the set of the Right Hand Side of the Equals operation
 * @param sizeRHS the number of possible elements the Right Hand Side set can have
 * @return true when both sets have the same elements. Note that sizeRHS and sizeLHS need not be equal!
 */
bool Equals(const bool setLHS[], size_t sizeLHS, const bool setRHS[], size_t sizeRHS);

/**
 * Writes to output the integer numbers that are contained in the set represented by the parameters.
 * It will only output the integers separated by space
 * @param output the stream to send the output
 * @param set the array of bool that represents whether a number is part of the set or not.
 * @param size the number of elements of the array
 */
void WriteSet(ostream& output, const bool set[], size_t size);

/**
 * Reads from the input stream the numbers that are going to be inserted into the set. It is possible that
 * some numbers will not be added to the set.
 * @param input the input stream to read from
 * @param set the array of bool that represents whether a number is part of the set or not.
 * @param size the number of elements of the array
 * @return the numbers of elements actually added to the set
 */
size_t ReadSet(istream& input, bool set[], size_t size);

/**
 * Gets the number of elements in the set
 * @param set the array of bool that represents whether a number is part of the set or not.
 * @param size the number of elements of the array
 * @return the number of elements of the set
 */
size_t Size(const bool set[], size_t size); 
```


> Note that the number of elements in the **array** is not the same as the number of elements in the set. A set represented by `bool a[5] = {true, true, false, false, false}` would have 2 elements even though the **array** has 5 elements.


### The set representation
The set is represented with an array of `bool`. The arrays have an associated `size`. This size represents the universe of the set, that is the possible elements that the set can hold.

For example:
```c++
    bool a[5] = {false, true, false, true, true};
    bool b[10] = {false};
```
The previous two declarations would represent two sets `a` and `b`. In the case of set `a` its universe is $U=\\{0,1,2,3,4\\}$, and in the case of `b` its universe is $U=\\{0,1,2,3,4,5,6,7,8,9\\}$. The universe is determined by the size of the array, the size of the array *does not* represent the elements but what elements **could** be in the set. So the actual sets would be $a=\\{1,3,4\\}$ and $b=\\{\\}$. `a` has elements 1, 3 and 4 because `a[1]`, `a[3]`, and `a[4]` are true, meaning that those elements are in the set. In the case of `b` it is the empty set because all its elements are set to `false`.

### The set operations
In this section there will be some examples of the operations.
```c++
    const int U = 5;
    bool s[U], t[U], r[U];
    InitializeSet(s, U); // Sets ALL elements of s to false
    InitializeSet(t, U);
    WriteSet(cout, s, U); // Prints... nothing on cout
    AddElement(s, U, 1); // sets the element 1 to true ~ Adds 1 to the set s
    WriteSet(cout, s, U); // Prints 1  to cout (there is a space after the 1)
    AddElement(s, U, 4);
    AddElement(t, U, 0);
    AddElement(t, U, 4);
    WriteSet(cout, s, U); // Prints 1 4  to cout (there is a space after the 4)
    WriteSet(cout, t, U); // Prints 0 4  to cout (there is a space after the 4)
    Intersection(s, U, t, U, r, U);
    WriteSet(cout, r, U); // prints 4  to cout (remember the space after the last element)
    Union(s, U, t, U, r, U);
    WriteSet(cout, r, U); // prints 0 1 4  to cout
    Complement(r, U);
    WriteSet(cout, r, U); // prints 2 3  to cout
    
    cout << Belongs(r, U, 1) << endl; // outputs false 
    cout << Belongs(r, u, 2) << endl; // outputs true
    cout << Equals(s, U, t, U) << endl; // outputs false {1, 4} != {0, 4}

```

Here are some resources about set operations:
* https://www.probabilitycourse.com/chapter1/1_2_2_set_operations.php
* https://www.cuemath.com/algebra/operations-on-sets/
* https://www.tutorialspoint.com/set-operations


## Files you are given

- `main.cpp` this file contains the `main` and `Test` functions. **DO NOT** modify this file in any way. The `main` function will execute 61 tests on the operations that you are requested to implement.
- `integer_set.h` this file contains the declaration of all the functions you need to implement. **DO NOT** modify this file in any way.
- `integer_set.cpp` on this file you will work. In this file you will write the implementation of all the functions declared in `integer_set.h`. You may add helper functions, but you _must_ implement the functions that are declared in the header file as they are.
- `CMakeLists.txt` this file contains the instructions for the compiler on how to build your program. **DO NOT** modify this file in any way.

## Possible Steps

The first recommended step is to write the function headers in `integer_set.cpp` and create the stub for each function. For example if the declaration of a function is:
```c++
int CountChocula(double data[], unsigned int size);
```
Then the function stub on its CPP file would be:
```c++
int CountChocula(double data[], unsigned int size){
    return INT_MAX;
}
```
Make sure your returning-value functions return an "impossible" number, this way you would guarantee that if a function has not been implemented you don't pass the test associated with the function by chance. Once you have done the stubs, the program should compile, and you should be able to start implementing the requested functions.

The following table shows you a possible order to implement the functions. For instance, if you implement `Initialize` and `Size` correctly you should pass tests 1, 2 and 3. Once you pass those three tests, you can move on to implement `AddElement`, if you do it correctly then you would pass tests 1 through 7. Continue doing so, until you pass all tests.

| Function(s)             | Test Numbers |
|-------------------------|--------------|
| `InitializeSet`, `Size` | 1 - 3        |
| `AddElement`            | 4 - 7        |
| `Belongs`               | 8 - 13       |
| `ReadSet`               | 14 - 29      |
| `WriteSet`              | 30 - 31      |
| `Equals` (a)            | 32 - 36      |
| `Complement`            | 37 - 42      |
| `Intersection` (a)      | 43 - 44      |
| `Union` (a)             | 45 - 46      |
| `Equals` (b)            | 47 - 48      |
| `Intersection` (b)      | 49 - 57      |
| `Union` (b)             | 58 - 61      |

> Note: remember that if your submitted code does not compile you will not get any credit for your assignment. **Make sure** your code compiles. If you don't pass all 61 tests, you will get partial credit for the tests that you pass, as long as it is because of good implementation of your functions and not random chance.

### How to determine the order of functions to be implemented
In the future you may not be given the previous section explaining the order in which you should do your assignment. To determine the order you just need to see the function that starts the tests. In `main.cpp` you can see this in the first lines:

```c++
    InitializeSet(a, 5);
    InitializeSet(b, 5);
    InitializeSet(c, 5);

    // Check Size
    Test(Size(a, 5) == 0, "Size #1", passedTests);
    Test(Size(b, 5) == 0, "Size #2", passedTests);
    Test(Size(c, 5) == 0, "Size #3", passedTests);

```

From there you can deduce that the first function you should implement are `InitializeSet` and `Size`. Following along the `main` function you will see the rest of the tests and the functions that are called.

## Expected Output
Once you have correctly implemented all functions, the output of your program should look like this:

```
TEST PASSED (Size #1                                 ) Total Passed: 1
TEST PASSED (Size #2                                 ) Total Passed: 2
TEST PASSED (Size #3                                 ) Total Passed: 3
TEST PASSED (AddElement #1 Successful                ) Total Passed: 4
TEST PASSED (AddElement #2 Successful                ) Total Passed: 5
TEST PASSED (AddElement #3 Out of Range Caught       ) Total Passed: 6
TEST PASSED (Size a = 2                              ) Total Passed: 7
TEST PASSED (0 Belongs to a                          ) Total Passed: 8
TEST PASSED (1 does not Belongs to a                 ) Total Passed: 9
TEST PASSED (2 Belongs to a                          ) Total Passed: 10
TEST PASSED (3 does not Belongs to a                 ) Total Passed: 11
TEST PASSED (4 does not Belongs to a                 ) Total Passed: 12
TEST PASSED (9 does not Belongs to a                 ) Total Passed: 13
TEST PASSED (Read count correct                      ) Total Passed: 14
TEST PASSED (Size b = 3                              ) Total Passed: 15
TEST PASSED (0 Belongs to b                          ) Total Passed: 16
TEST PASSED (1 Belongs to b                          ) Total Passed: 17
TEST PASSED (2 does not Belongs to b                 ) Total Passed: 18
TEST PASSED (3 Belongs to b                          ) Total Passed: 19
TEST PASSED (4 does not Belongs to b                 ) Total Passed: 20
TEST PASSED (9 does not Belongs to b                 ) Total Passed: 21
TEST PASSED (Read count correct                      ) Total Passed: 22
TEST PASSED (Size b = 3                              ) Total Passed: 23
TEST PASSED (0 Belongs to b                          ) Total Passed: 24
TEST PASSED (1 Belongs to b                          ) Total Passed: 25
TEST PASSED (2 does not Belongs to b                 ) Total Passed: 26
TEST PASSED (3 Belongs to b                          ) Total Passed: 27
TEST PASSED (4 does not Belongs to b                 ) Total Passed: 28
TEST PASSED (9 does not Belongs to b                 ) Total Passed: 29
TEST PASSED (Write Test #1                           ) Total Passed: 30
TEST PASSED (Write Test #2                           ) Total Passed: 31
TEST PASSED (Reflexive a == a                        ) Total Passed: 32
TEST PASSED (a == c                                  ) Total Passed: 33
TEST PASSED (c == a                                  ) Total Passed: 34
TEST PASSED (a != b                                  ) Total Passed: 35
TEST PASSED (b != a                                  ) Total Passed: 36
TEST PASSED (After complement, Size c = 3            ) Total Passed: 37
TEST PASSED (0 does not Belongs to c                 ) Total Passed: 38
TEST PASSED (1 Belongs to c                          ) Total Passed: 39
TEST PASSED (2 does not Belongs to c                 ) Total Passed: 40
TEST PASSED (3 Belongs to c                          ) Total Passed: 41
TEST PASSED (4 Belongs to c                          ) Total Passed: 42
TEST PASSED (Intersection a - b Successful           ) Total Passed: 43
TEST PASSED (Intersection result OK                  ) Total Passed: 44
TEST PASSED (Union a - b Successful                  ) Total Passed: 45
TEST PASSED (Union result OK                         ) Total Passed: 46
TEST PASSED (b == x                                  ) Total Passed: 47
TEST PASSED (b != y                                  ) Total Passed: 48
TEST PASSED (Intersection a5 - x10 -> r5 successful  ) Total Passed: 49
TEST PASSED (Intersection a5 - x10 result correct    ) Total Passed: 50
TEST PASSED (Intersection a5 - y10 -> r5 successful  ) Total Passed: 51
TEST PASSED (Intersection a5 - y10 result correct    ) Total Passed: 52
TEST PASSED (Intersection z10 - a5 -> r5 successful  ) Total Passed: 53
TEST PASSED (Intersection z10 - a5 result correct    ) Total Passed: 54
TEST PASSED (Intersection x10 - y10 -> r5 successful ) Total Passed: 55
TEST PASSED (Intersection x10 - y10 result correct   ) Total Passed: 56
TEST PASSED (Intersection z10 - y10 -> r5 unsuccessful) Total Passed: 57
TEST PASSED (Union x10 - a5 -> r5 successful         ) Total Passed: 58
TEST PASSED (Union x10 - a5 -> r5 result correct     ) Total Passed: 59
TEST PASSED (Union y10 - b5 -> r5 unsuccessful       ) Total Passed: 60
TEST PASSED (Union z10 - c5 -> r5 unsuccessful       ) Total Passed: 61
```

## Grading
The number of test you need to pass is 61, if you pass them all then your _raw_ grade will be 100, this is assuming you don't get any deductions on good programming practices. If you pass 25 tests, then your _raw_ grade would be $25/61 * 100 = 40.98$.

## Deductions

* For each infraction on good programming practices there will be a deduction of 5 points
* If the program has a runtime error (the program crashes) there will be a deduction of 10 points
* If the program does not have comment headers there will be a deduction of 5 points
* If the program does not have comments on functions and appropriate additional comments there will be a deduction of 5 points
* If the program does not follow instructions, for instance if you did not implement any of the requested functions, there will be a deduction of 5 points per ignored instruction
* If the program does not compile, the grade will be zero.

NOTE: Remember to check the Canvas Page about Programming Practices and the course coding conventions.


## Academic Integrity

This programming assignment is to be done on an **individual** basis. At the same time, it is understood that learning from your peers is valid, and you are encouraged to talk among yourselves about programming in general and current assignments in particular.  Keep in mind, however, that each individual student must do the work in order to learn.

Hence, the following guidelines are established:
* Feel free to discuss any and all programming assignments but do not allow other students to look at or copy your code. Do not give any student an electronic or printed copy of any program you write for this class.
* Gaining the ability to properly analyze common programming errors is an important experience. Do not deprive a fellow student of his/her opportunity to practice problem-solving: control the urge to show them what to do by writing the code for them.
* If you’ve given the assignment a fair effort and still need help, see the instructor or a lab assistant.
* **If there is any evidence that a program or other written assignment was copied from another student (or from any source), neither student will receive any credit for it. This rule will be enforced: It is possible to fail the class for cheating on a programming assignment.**
* Protect yourself: Handle throw-away program listings carefully.
* Remember to read the Academic Integrity guidelines provided in the class syllabus.
* DO NOT copy code from any source, **ALL** the submitted code should be written by you (except the code that is given).
