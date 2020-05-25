#include <iostream>
using namespace std;

/*Copies one integer array into another
/*
 * Author: Marisa Persaud
 * Project: Fun with Pointers
 * Purpose: Copy elements from one array to another using pointer notation
 */

/*Copies elements from one integer array to another
------------------------------------------
 Preconditions: Two pointers to arrays full to at least "size" size.
 Postconditions: Both arrays will have the same elements
*/
void copy(int* dest, int* src, int size);


/*Prints an integer array
------------------------------------------
 Preconditions: toPrint is full until size
 Postconditions: Both elements are untouched.
*/
void print(int* toPrint, int size);

/*Creates an integer array with user input
------------------------------------------
 Preconditions: toFill is at least the size of "size"
 Postconditions: toFill is full of "size" elements
*/
void initialize(int* toFill, int size);


int main() {
	int *first = nullptr,  //pointer to dynamic array to be initially filled
		*second = nullptr, //pointer to dynamic array to be filled with first's contents
		*initialFirst = nullptr,//will be a ptr to first's initial element
		*initialSecond = nullptr, //will be a ptr to second's initial element
		size; //size of the arrays

	cout << "Enter in the number of integers to be copied: ";
	cin >> size;
	if (size > 0) {
		first = new int[size];
		second = new int[size];
		
		initialize(first, size); //Fill the array with "size" number of elements
		
		cout << "\nThe first array is: ";
		print(first, size);

		copy(second, first, size); //Copy the first array into the second array

		cout << "\nThe second array now is: ";
		print(second, size);
		cout << endl;

		delete[] first;
		delete[] second;
	}
	else
		cout << "Empty arrays requested. Exiting.\n";
    return 0;
}

void print(int* toPrint, int size) {
	for (int i = 0; i < size; i++) {
		cout << *toPrint << " ";
		toPrint++;
	}
}

void copy(int* dest, int* src, int size) {
	for (int i = 0; i < size; i++) {
		*dest = *src;
		dest++;
		src++;
	}
};

void initialize(int* toFill, int size) {
	cout << "Enter in " << size << " integers: \n";
	for (int i = 0; i < size; i++) {
		cin >> *toFill;
		toFill++;
	}
}
