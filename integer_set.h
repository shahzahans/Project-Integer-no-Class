/**
 * Title:   Integer Set v1
 * Purpose: Create the functions to simulate some operations over an integer set
 *          ---------------------------------------------
 *          D O   N O T   M O D I F Y   T H I S   F I L E
 *          ---------------------------------------------
 * Author: Carlos R. Arias
 * Date:    2022-12-12
 */

#ifndef INTEGERSET_NOCLASS_ASSIGNMENT_INTEGER_SET_H
#define INTEGERSET_NOCLASS_ASSIGNMENT_INTEGER_SET_H

#include <iostream>
using std::ostream;
using std::istream;

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
 * the Left Hand Side, and RHS for the Right Hand Side of the operation. This operation returns true
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
size_t Size(const bool set[], size_t size); // counts how many elements in the set


#endif //INTEGERSET_NOCLASS_ASSIGNMENT_INTEGER_SET_H
