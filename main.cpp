/**
 * Title:   Integer Set v1
 * Purpose: Create the functions to simulate some operations over an integer set.
 *          This main contains the tests for each of the operations of the integer set.
 *          There is a total of 60 tests to pass.
 *          ---------------------------------------------
 *          D O   N O T   M O D I F Y   T H I S   F I L E
 *          ---------------------------------------------
 * Author:  Carlos R. Arias
 * Date:    2022-12-12
 */

#include <iostream>
#include <sstream>
#include <iomanip>

#include "integer_set.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::setw;
using std::left;

void Test(bool condition, const char* message, unsigned int& passedTests);

int main(int argc, char* argv[]) {
    unsigned int passedTests = 0;
    bool flag;

    // PHASE I, All sets with U = {0, 1, 2, 3, 4}
    bool a[5], b[5], c[5], r5[5];

    // Initialize
    InitializeSet(a, 5);
    InitializeSet(b, 5);
    InitializeSet(c, 5);

    // Check Size
    Test(Size(a, 5) == 0, "Size #1", passedTests);
    Test(Size(b, 5) == 0, "Size #2", passedTests);
    Test(Size(c, 5) == 0, "Size #3", passedTests);

    // Check AddElement
    flag = AddElement(a, 5, 0);
    Test(flag, "AddElement #1 Successful", passedTests);
    flag = AddElement(a, 5, 2);
    Test(flag, "AddElement #2 Successful", passedTests);
    flag = AddElement(a, 5, 5);
    Test(!flag, "AddElement #3 Out of Range Caught", passedTests);
    Test(Size(a, 5) == 2, "Size a = 2", passedTests);

    // Check Belongs
    flag = Belongs(a, 5, 0);
    Test(flag, "0 Belongs to a", passedTests);
    flag = Belongs(a, 5, 1);
    Test(!flag, "1 does not Belongs to a", passedTests);
    flag = Belongs(a, 5, 2);
    Test(flag, "2 Belongs to a", passedTests);
    flag = Belongs(a, 5, 3);
    Test(!flag, "3 does not Belongs to a", passedTests);
    flag = Belongs(a, 5, 4);
    Test(!flag, "4 does not Belongs to a", passedTests);
    flag = Belongs(a, 5, 9);
    Test(!flag, "9 does not Belongs to a", passedTests);

    // Check ReadSet
    stringstream stream("0 1 3");
    Test(ReadSet(stream, b, 5) == 3, "Read count correct", passedTests);
    Test(Size(b, 5) == 3, "Size b = 3", passedTests);
    flag = Belongs(b, 5, 0);
    Test(flag, "0 Belongs to b", passedTests);
    flag = Belongs(b, 5, 1);
    Test(flag, "1 Belongs to b", passedTests);
    flag = Belongs(b, 5, 2);
    Test(!flag, "2 does not Belongs to b", passedTests);
    flag = Belongs(b, 5, 3);
    Test(flag, "3 Belongs to b", passedTests);
    flag = Belongs(b, 5, 4);
    Test(!flag, "4 does not Belongs to b", passedTests);
    flag = Belongs(b, 5, 9);
    Test(!flag, "9 does not Belongs to b", passedTests);

    // Check ReadSet with numbers outside the U
    InitializeSet(b, 5);
    stream.clear();
    stream.str("0 1 3 8");
    Test(ReadSet(stream, b, 5) == 3, "Read count correct", passedTests);
    Test(Size(b, 5) == 3, "Size b = 3", passedTests);
    flag = Belongs(b, 5, 0);
    Test(flag, "0 Belongs to b", passedTests);
    flag = Belongs(b, 5, 1);
    Test(flag, "1 Belongs to b", passedTests);
    flag = Belongs(b, 5, 2);
    Test(!flag, "2 does not Belongs to b", passedTests);
    flag = Belongs(b, 5, 3);
    Test(flag, "3 Belongs to b", passedTests);
    flag = Belongs(b, 5, 4);
    Test(!flag, "4 does not Belongs to b", passedTests);
    flag = Belongs(b, 5, 9);
    Test(!flag, "9 does not Belongs to b", passedTests);

    // Check WriteSet
    stream.clear();
    stream.str("");
    WriteSet(stream, a, 5);
    Test(stream.str() == "0 2 ", "Write Test #1", passedTests);
    stream.clear();
    stream.str("");
    WriteSet(stream, b, 5);
    Test(stream.str() == "0 1 3 ", "Write Test #2", passedTests);

    AddElement(c, 5, 0);
    AddElement(c, 5, 2);

    // Check Equals
    Test(Equals(a, 5, a,5), "Reflexive a == a", passedTests);
    Test(Equals(a, 5, c,5), "a == c", passedTests);
    Test(Equals(c, 5, a,5), "c == a", passedTests);
    Test(!Equals(a, 5, b,5), "a != b", passedTests);
    Test(!Equals(b, 5, a,5), "b != a", passedTests);

    // Check Complement
    Complement(c, 5);
    Test(Size(c, 5) == 3, "After complement, Size c = 3", passedTests);
    flag = Belongs(c, 5, 0);
    Test(!flag, "0 does not Belongs to c", passedTests);
    flag = Belongs(c, 5, 1);
    Test(flag, "1 Belongs to c", passedTests);
    flag = Belongs(c, 5, 2);
    Test(!flag, "2 does not Belongs to c", passedTests);
    flag = Belongs(c, 5, 3);
    Test(flag, "3 Belongs to c", passedTests);
    flag = Belongs(c, 5, 4);
    Test(flag, "4 Belongs to c", passedTests);

    InitializeSet(c, 5);
    Complement(c, 5);

    // Check Intersection
    flag = Intersection(a, 5, b, 5, r5, 5);
    Test(flag, "Intersection a - b Successful", passedTests);
    stream.clear();
    stream.str("");
    WriteSet(stream, r5, 5);
    Test(stream.str() == "0 ", "Intersection result OK", passedTests);

    // Check Union
    flag = Union(a, 5, b, 5, r5, 5);
    Test(flag, "Union a - b Successful", passedTests);
    stream.clear();
    stream.str("");
    WriteSet(stream, r5, 5);
    Test(stream.str() == "0 1 2 3 ", "Union result OK", passedTests);

    // PHASE II, Sets with U = {0, 1, 2, 3, 4} and others with U = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

    bool    // Manual Initialization of the x, y, z sets (Faster)
    x[10] = {1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            y[10] = {0, 0, 1, 1, 0, 0, 0, 0, 1, 0},
            z[10] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
            r10[10];

    // Comparing sets with different universes
    Test(Equals(b, 5, x,10), "b == x", passedTests);
    Test(!Equals(b, 5, y,10), "b != y", passedTests);

    // Intersection Tests
    // 1
    flag = Intersection(a, 5, x, 10, r5, 5);
    Test(flag, "Intersection a5 - x10 -> r5 successful", passedTests);
    stream.clear();
    stream.str("");
    WriteSet(stream, r5, 5);
    Test(stream.str() == "0 ", "Intersection a5 - x10 result correct", passedTests);
    // 2
    flag = Intersection(a, 5, y, 10, r5, 5);
    Test(flag, "Intersection a5 - y10 -> r5 successful", passedTests);
    stream.clear();
    stream.str("");
    WriteSet(stream, r5, 5);
    Test(stream.str() == "2 ", "Intersection a5 - y10 result correct", passedTests);
    // 3
    flag = Intersection(z, 10, a, 5, r5, 5);
    Test(flag, "Intersection z10 - a5 -> r5 successful", passedTests);
    stream.clear();
    stream.str("");
    WriteSet(stream, r5, 5);
    Test(stream.str() == "0 2 ", "Intersection z10 - a5 result correct", passedTests);
    // 4
    flag = Intersection(x, 10, y, 10, r5, 5);
    Test(flag, "Intersection x10 - y10 -> r5 successful", passedTests);
    stream.clear();
    stream.str("");
    WriteSet(stream, r5, 5);
    Test(stream.str() == "3 ", "Intersection x10 - y10 result correct", passedTests);
    // 5 (non successful)
    flag = Intersection(z, 10, y, 10, r5, 5);
    Test(!flag, "Intersection z10 - y10 -> r5 unsuccessful", passedTests);

    // Union Tests
    // 1
    flag = Union(x, 10, a, 5, r5, 5);
    Test(flag, "Union x10 - a5 -> r5 successful", passedTests);
    stream.clear();
    stream.str("");
    WriteSet(stream, r5, 5);
    Test(stream.str() == "0 1 2 3 ", "Union x10 - a5 -> r5 result correct", passedTests);
    // 2
    flag = Union(y, 10, b, 5, r5, 5);
    Test(!flag, "Union y10 - b5 -> r5 unsuccessful", passedTests);
    // 3
    flag = Union(z, 10, c, 5, r5, 5);
    Test(!flag, "Union z10 - c5 -> r5 unsuccessful", passedTests);

    return 0;
}

void Test(bool condition, const char* message, unsigned int& passedTests){
    if (condition){
        cout << "TEST PASSED (" << left << setw(40) << message << ") Total Passed: " << ++passedTests << endl;
    }else{
        cout << "TEST FAILED (" << message << ")" << endl;
    }
}

