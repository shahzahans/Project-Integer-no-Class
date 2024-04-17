/**
 * Title:   Integer Set v1
 * Purpose: Implement C++ function that represent integer set operation
 * Author: **<Shadman Shahzahan>
 * Date: January 31, 2024
 */

using namespace std;
#include "integer_set.h"
#include <fstream>
#include <string>



//Initialization
void InitializeSet(bool set[], size_t size){ // Intializing set to remain false
    for(int i = 0; i < size; i++){
        set[i] = false;
    }

}


bool AddElement(bool set[], size_t size, size_t element){
    //Adding Elements to the sets if it is within the valid range.

    if(element < size) {
        set[element] = true;
        return true;
    }
    else {
        return false;
    }

}

//Belongs
bool Belongs(const bool set[], size_t size, size_t element){ //Checks if an element is present or not in the set.
    return set[element];
}

//Intersection
bool Intersection(const bool setLHS[], size_t sizeLHS, const bool setRHS[], size_t sizeRHS, bool set[], size_t size){ //compares and stores the similar index

    bool isValid;

    InitializeSet(set, size);

    //Find the size of the larger set
    size_t largest = max(sizeLHS, sizeRHS);

    //Iterate through sets to find common elements
    for (size_t i = 0; i < largest; i++) {
        if (setLHS[i] && setRHS[i]){
            //Add common elements to the result set
            isValid = AddElement(set, size, i);
            if(!isValid){
                //break if an error occurs during addition
                break;
            }
        }

    }
    return isValid;
}

//Union
bool Union(const bool setLHS[], size_t sizeLHS, const bool setRHS[], size_t sizeRHS, bool set[], size_t size){ // compare and stores index that is not present on sets
    bool isValid;
    size_t i;

    InitializeSet(set, size);


    size_t smallest;
    size_t largest;
    bool large;

    //Find the sizes of both sets
    if (sizeLHS > sizeRHS){
        largest = sizeLHS;
        smallest = sizeRHS;
        large = true;
    } else {
        largest = sizeRHS;
        smallest = sizeLHS;
        large = false;
    }

    // Iterate through the smaller set to add its elements
    for (i = 0; i < smallest; i++) {
        if ((setLHS[i] || setRHS[i])){
            // Add elements to result set
            isValid = AddElement(set, size, i);
            if(!isValid){
                //break if an error occurs during addition
                break;
            }
        }

    }

    // Iterate through the remaining elements in the larger set
    for (; i < largest; i++) {
        if (large){
            if(setLHS[i]) {
                isValid = AddElement(set, size, i);
                if (!isValid) {
                    //break if an error occurs during addition
                    break;
                }
            }
        } else {
            if(setRHS[i]) {
                isValid = AddElement(set, size, i);
                if (!isValid) {
                    //break if an error occurs during addition
                    break;
                }
            }
        }

    }
    return isValid;
}



//Complement
void Complement(bool set[], size_t size){ // Reverse all the elements in the whole set
    for(size_t i = 0; i < size; i++){
        set[i] = !set[i];
    }

}

// Equals
bool Equals(const bool setLHS[], size_t sizeLHS, const bool setRHS[], size_t sizeRHS){
    // Checks if two sets are equal.
    for (size_t i = 0; i < sizeLHS; i++){
        if (setLHS[i] != setRHS[i]){
            return false;
        }
    }

    return true;

}

//Write to a Stream
void WriteSet(ostream& output, const bool set[], size_t size){
    // Writes set elements to the output stream
    for (int i = 0; i < size; i++) {
        if (set[i]){
            output << i << " ";
        }
    }



}

//Read to a Stream
size_t ReadSet(istream& input, bool set[], size_t size){
    string var;
    size_t returnVal = 0;
    size_t inputSize = var.size();
    getline(input, var);


    for(int i = 0; i < size; i++){
        if(var[i] != ' ') {
            set[var[i] - '0'] = true;
            returnVal++;
        }

    }
    return returnVal;
}

//Get the number of elements in the set
size_t Size(const bool set[], size_t size){
    // Counts the number of true values in the set
    size_t size_of_set = 0;
    for (int i = 0; i < size; i++){
        if (set[i]){
            size_of_set += 1;
        }
    }
    return size_of_set;
}