/*
 * Author: Marisa Persaud
 * Project: Fun with 2D Pointers
 * Purpose: To build a library of functions which work with an array of pointers to pointers
 * Notes: Rememebr that my 1D array is slightly different
 */


#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
T** allocate2D(int size);
/*Creates a dynamic array of pointers to pointers of "size" size*/

template <typename T>
T* allocate1D(int size);
/*Creates a dynamic array of "size" size*/

template <typename T>
void initialize(const int* sizes, T** rows, const int rows_size);
/*Initialize each entry in a dynamic array of pointers to pointers(rows) to a dynamic array of with a size
corresponding to that in the "sizes" array. Fills each array with ints. 
The last entry of "rows" is initialized to the nullptr.*/

template <typename T>
void print(const int * sizes, T** rows);
/*Prints every entry in rows*/

template <typename T>
T read(const int* sizes, T** rows, const int rows_size, const int row, const int column);
/*Returns the contents of (rows[row-1], rows[row-1][column - 1]) if it exists. CAN RETURN A FLAG*/

template <typename T>
bool write(const int* sizes, T** rows, const T value, const int rows_size, const int row, const int column);
/*Writes a value to (rows[row-1], rows[row-1][column - 1]) if it exists*/

template <typename T>
T * get(const int* sizes, T** rows, const int rows_size, const int row, const int column);
/*Gets the entry at (rows[row-1], rows[row-1][column - 1]) if it exists*/

bool isValid(const int* sizes, const int rows_size, const int row, const int column);
/*Returns if the entry at (rows[row-1], rows[row-1][column - 1]) exists*/

template <typename T>
void deallocate(T** rows);
/*Deallocates all of the entries in rows*/

int main() {
	int** two_d = nullptr;
	int sizes[5] = {2,4,6,8,10};

	two_d = allocate2D<int>(5);
	initialize(sizes, two_d, 5);
	print(sizes, two_d);

	cout << "\nThe entry at (1, 1): " << read(sizes, two_d, 5, 1, 1);
	cout << "\nThe entry at (3,3): " << read(sizes, two_d, 5, 3, 3);
	cout << "\nThe entry at (5, 10): " << read(sizes, two_d, 5, 5, 10);
	cout << "\nThe entry at (3, 6): " << read(sizes, two_d, 5, 3, 6);
	//cout << "\nThe entry at (6, 1): " << read(sizes, two_d, 5, 6, 1); //Will now trigger an assert
    cout << "\n\nWrite (5, 10) with 66:"; write(sizes, two_d, 66, 5, 5, 10);
	cout << "\nWrite (3, 4) with 66:";  write(sizes, two_d, 66, 5, 3, 4);
	cout << "\nWrite (1, 1) with 66:\n";  write(sizes, two_d, 66, 5, 1, 1);
	print(sizes, two_d);
	cout << "\nThe entry at (1, 1): " << read(sizes, two_d, 5, 1, 1);

	deallocate(two_d);

	delete[] two_d;
	return 0;
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
void initialize(const int* sizes, T ** rows, const int rows_size) {
	assert((sizes != nullptr) && (rows != nullptr) && (rows_size >= 0));

	const int* sizes_walker = sizes;
	T** rows_walker = rows;

	for (int i = 0; i < rows_size; i++) {
		T* new_column = allocate1D<int>((*sizes_walker));
		*rows_walker = new_column;

		for (int j = 0; j < *sizes_walker; j++) {
			*new_column = (i * 10) + j;
			new_column++;
		}
		sizes_walker++;
		rows_walker++;
	}
	//The last entry is initialized to nullptr.
    *rows_walker = nullptr;
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

	cout << endl;
	while(*rows_walker != nullptr){
		T* walker = *rows_walker;

		for (int i = 0; i < *sizes_walker; i++) {
			cout << *walker << " ";
			walker++;
		}

		sizes_walker++;
		rows_walker++;
		cout << endl;
	}

}

/*Returns the contents of (rows[row-1], rows[row-1][column - 1]) if it exists. Quits if passed an invalid
value.
I'm too tired to fill in the rest of these comments right now. I'll fill them out on lab and plane
*/
template <typename T>
T read(const int* sizes, T** rows, const int rows_size, const int row, const int column) {
	T* value = get(sizes, rows, rows_size, row, column);
	
	//if a valid address is returned by get
	assert(value != nullptr);
	return *value;
}

/*Writes a value to (rows[row-1], rows[row-1][column - 1]) if it exists*/
template <typename T>
bool write(const int* sizes, T** rows, const T value, const int rows_size, const int row, const int column) {
	T* address = get(sizes, rows, rows_size, row, column);
	bool successful_write = false; //if the write has been successful

	//if a valid address is returned by get
	if (address != nullptr) {
		*address = value;
		successful_write = true;
	}

	return successful_write;
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
	
	if (isValid(sizes, rows_size, row, column)) {
		row_address = rows + (row - 1);
		address = *row_address; //Address is storing the entry at "row" ([][][*][][][])
		address = address + (column -1); //Address now stores the entry at "column"
		/*[][][ ][][][]
		      [ ]
			  [*]
			  [ ]
		*/
	}
	return address;
}

/*Returns if the entry at (rows[row-1], rows[row-1][column - 1]) exists
-----------------------------------------------------------------------
Preconditions: "sizes" contains the valid sizes of all of the arrays in the list; "rows_size" is the valid
               size of the list; "rows_size", "row", and "column" are greater than or equal to 0
Postconditions: All are unchanged. 
*/
bool isValid(const int* sizes, const int rows_size, const int row, const int column) {

	assert((sizes != nullptr ) && (row >= 0) && (column >= 0));
	bool valid = true;

	//If the row is valid
	if ((row - 1) > rows_size) {
		valid = false;
	}
	else {	
		//Go to if the column is valid

		//The size of the array column which is being referenced
		const int* ptr_to_size = sizes + (row - 1);
		int arr_size = *ptr_to_size;

		//if the column being asked for is greater than the size of the array
		if (arr_size < column) {
			valid = false;
		}
	}
	return valid;
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

