#pragma once

//This does NOT like having an ifndef added to it.

#include <iostream>
#include <cassert>
using namespace std;

/**************************************************************************************
DEFINITIONS
***************************************************************************************
*/

template <typename T>
void print1D(const T* row, const int size, const T false_value);
/*Prints one array in correct format*/

template <typename T>
T* allocate1D(int size);
/*Creates a dynamic array of "size" size*/


template <typename T>
T* intialize1D(T* row, int size, T value = T());
/*Initalizes a 1D array to be full to "size" of "value"*/

/**************************************************************************************
FUNCTIONS
***************************************************************************************
*/

/*Prints one array in the correct format
----------------------------------
Preconditions: "size" is correct size of "row"
Postconditions: Everything is untouched.
*/
template <typename T>
void print1D(const T* row, const int size, const T false_value) {
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ": ";
		if (*row == false_value) {
			//A false outputs the necessary character
			cout << "Empty ";
		}
		else
			//A true means the place is reserved and produces an "X"
			cout << *row << " ";
		row++;
	}
}

/*Creates a dynamic array of pointers of "size" size
----------------------------------------------------------------
Preconditions: size > 0, there is available memory
Postconditions: An array of "size" size of pointer has been created and returned
*/
template <typename T>
T* allocate1D(int size) {
	assert(size >= 0);

	T* new_column = new T[size];
	return new_column;
}

/*Initalizes a 1D array to be full to "size" of "value"
-------------------------------------------------------
Preconditions: "row" points to a block "size" value
Postconditions: each value of the array contains "value"
*/
template <typename T>
T* intialize1D(T* row, int size, T value) {
	for (int j = 0; j < size; j++) {
		*row = value;   //Initially all the places are not reserved
		row++;
	}
	return row;

}
