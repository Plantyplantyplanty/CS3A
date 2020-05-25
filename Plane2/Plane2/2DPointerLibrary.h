#pragma once


#include <iostream>
#include <cassert>
#include "Plane.h"
using namespace std;

/**************************************************************************************
DEFINITIONS
***************************************************************************************
*/

template <typename T>
T read(const int* sizes, T** rows, const int rows_size, const int row, const int column);
/*Returns the contents of (rows[row-1], rows[row-1][column - 1]) if it exists, or a flag of 2*/

template <typename T>
bool write(const int* sizes, T** rows, const T value, const int rows_size, const int row, const int column);
/*Writes "value" to (rows[row-1], rows[row-1][column - 1]) if it exists*/

template <typename T>
void print(const int* sizes, T** rows);
/*Prints every entry in rows*/

template <typename T>
void print(const T* row, const int size);
/*Prints one array in correct format*/

template <typename T>
T** allocate2D(int size);
/*Creates a dynamic array of pointers to pointers of "size" size*/

template <typename T>
T* allocate1D(int size);
/*Creates a dynamic array of "size" size*/

template <typename T>
T ** initialize(const int* sizes, T** rows, const int rows_size);
/*Initialize each entry in a dynamic array of pointers to pointers(rows) to a dynamic array of with a size
corresponding to that in the "sizes" array. Fills each array with ints.
The last entry of "rows" is initialized to the nullptr.*/

template <typename T>
T* initialize1D(int size, T* new_column);
//Initializes a 1D array with false

template <typename T>
T* get(const int* sizes, T** rows, const int rows_size, const int row, const int column);
/*Gets the entry at (rows[row-1], rows[row-1][column - 1]) if it exists*/

template <typename T>
void deallocate(T** rows);
/*Deallocates all of the entries in rows*/

/*Returns if the entry at (rows[row-1], rows[row-1][column - 1]) exists*/
bool isValid(const int* sizes, const int rows_size, const int row, const int column);
/**************************************************************************************
FUNCTIONS
***************************************************************************************
*/

/*Returns the contents of (rows[row-1], rows[row-1][column - 1]) if it exists
-----------------------------------------------------------------------------
Preconditions: (rows[row-1], rows[row-1][column - 1]) exists. Sizes contains the valid size of the 
               arrays in "rows". 
Postconditions: All passed arguments are untouched. The program will fail if passed an invalid 
                value. 
*/
template <typename T>
T read(const int* sizes, T** rows, const int rows_size, const int row, const int column) {
	T* value = get(sizes, rows, rows_size, row, column); //gets the address of the value if it exists
	int fail = 2;

	//if a valid address is returned by "get"
	if (value != nullptr) {
		return *value;
	}
	else
		return fail;  //This will never execute under the new code, but is here as a template
	//NEED TO RETURN A FLAG
}

/*Writes a value to (rows[row-1], rows[row-1][column - 1]) if it exists
-----------------------------------------------------------------------
Preconditions: Preconditions: (rows[row-1], rows[row-1][column - 1]) exists. Sizes contains the valid 
               size of the arrays in "rows". Value is a valid value for the array.
Postconditions: (rows[row-1], rows[row-1][column - 1]) now contains "value". If it's not valid, then 
                the program fails. Returns if the write has been successful.
*/
template <typename T>
bool write(const int* sizes, T** rows, const T value, const int rows_size, const int row, const int column) {
	T* address = get(sizes, rows, rows_size, row, column);//gets the address of the value if it exists
	bool successful_write = false; //if the write has been successful.

	//if a valid address is returned by get
	if (address != nullptr) {
		*address = value;
		successful_write = true;
	}
	return successful_write;
}

/*Prints every entry in rows
-----------------------------
Preconditions:"rows" has been initialized; "sizes" contains the valid sizes of all of the arrays in "rows"
Postconditions: Everything is the same; all of "rows" has been outputted to the terminal
*/
template <typename T>
void print(const int* sizes, T** rows) {
	assert((sizes != nullptr) && (rows != nullptr));

	const int* sizes_walker = sizes;
	T** rows_walker = rows;
	int col = 1; //The column we are on

	cout << endl;
	while (*rows_walker != nullptr) {
		//T* walker = *rows_walker;

		cout << col << " ";
	    print(*rows_walker, *sizes_walker);

		col++;
		sizes_walker++;
		rows_walker++;
		cout << endl;
	}

}

/*Prints one array in correct form
----------------------------------
Preconditions: "size" is correct size of "row"
Postconditions: Everything is untouched.
*/
template <typename T>
void print(const T* row, const int size) {
	for (int i = 0; i < size; i++) {
		if (!(*row)) {
			//A false outputs the necessary character
			cout << char('A' + i) << " ";
		}
		else
			//A true means the place is reserved and produces an "X"
			cout << "X ";
		row++;
	}
}

/*Creates a dynamic array of pointers to pointers of "size" size
----------------------------------------------------------------
Preconditions: size > 0, there is available memory
Postconditions: An array of "size" size of pointers to pointer has been created and returned
*/
template <typename T>
T** allocate2D(int size) {
	assert(size >= 0);

	T** new_row = new T * [size + 1];
	return new_row;
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

/*Initialize each entry in a dynamic array of pointers to pointers("rows") to a dynamic array of with a size
corresponding to that in the "sizes" array. Fills each array with ints.
The last entry of "rows" is initialized to the nullptr.
----------------------------------------------------------------------------------------------------------
Preconditions: "sizes" contains the valid sizes of all of the arrays in "row", "rows" has been initialized
			   to "rows" size.
Postconditions: Rows has been initialized with "rows_size" - 1 arrays of sizes corresponding to those in the
				"sizes" array.
*/
template <typename T>
T ** initialize(const int* sizes, T** rows, const int rows_size) {
	assert((sizes != nullptr) && (rows != nullptr) && (rows_size >= 0));

	const int* sizes_walker = sizes;
	T** rows_walker = rows;

	for (int i = 0; i < rows_size; i++) {
		*rows_walker = allocate1D<bool>((*sizes_walker));
		*rows_walker = initialize1D(*sizes_walker, *rows_walker);

		sizes_walker++;
		rows_walker++;
	}
	//The last entry is initialized to nullptr.
	*rows_walker = nullptr;
	return rows;
}

/*Initializes a 1D array*/
template <typename T>
T * initialize1D(int size, T * new_column){
	T* walker = new_column;
	for (int j = 0; j < size; j++) {
		*walker = false;   //Initially all the places are not reserved
		walker++;
	}
	return new_column;
}


/*Gets the entry at (rows[row-1], rows[row-1][column - 1]) if it exists
------------------------------------------------------------------------
Preconditions: "sizes" contains the valid sizes of all of the arrays in "rows"; "rows_size" is the valid
			   size of the list; "rows_size", "row", and "column" are greater than or equal to 0; "rows"
			   has been initialized.
Postconditions: Everything is unchanged
*/
template <typename T>
T* get(const int* sizes, T** rows, const int rows_size, const int row, const int column) {
	assert((sizes != nullptr) && (rows != nullptr));

	T** row_address = nullptr; //so that I don't use *() notation
	T* address = nullptr;

	bool valid = isValid(sizes, rows_size, row, column);
	if (valid) {
		row_address = rows + row - 1;
		address = *row_address; //Address is storing the entry at "row" ([][][*][][][])
		address = address + (column - 1); //Address now stores the entry at "column"
		/*[][][ ][][][]
			  [ ]
			  [*]
			  [ ]
		*/
	}
	else {
		assert(valid);
	}
	return address;
}


/*Deallocates all of the entries in "rows"
-----------------------------------------
Preconditions: All of the entries "rows" have been initialized
Postconditions: All of the entries in "rows" have been deallocated
*/
template <typename T>
void deallocate(T** rows) {
	assert(rows != nullptr);

	while (*rows != nullptr) {
		delete[](*rows);
		rows++;
	}
}
