/*
 * Author:  Marisa Persaud
 * Project: Add Entry
 * Purpose: Continously add and subtract entries to an increasing and decreasing array
 *
 */

#include <iostream>
#include <cassert>
using namespace std;

/*Adds a new entry to the list. Doubles the array size if the array has reached capacity*/
template <typename T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity);

/*Removes the first instance of "delete_me" if it is in "list" and resizes the array*/
template <typename T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity);

/*Shifts everything from "entry" + 1 down so that entry is no longer in the list*/
template <typename T>
void shift_left(T* list, T* entry, int& size);

/*Returns a dynamic array of "capacity" size*/
template <typename T>
T* allocate(int capacity);

/*Reallocates the contents of "src" into a new dynamic array of "new_capacity" size*/
template <typename T>
T* reallocate(T* src, int& src_capacity, int& src_size, int new_capacity);

/*Copies "many_to_copy" entries from one array into another array*/
template <typename T>
void copy_list(T* dest, T* src, int many_to_copy);

/*Searches for "find_me" in list and returns its location*/
template <typename T>
T* search_entry(T* list, const T& find_me, const int size);

/*Prints "list" to the terminal screen*/
template <typename T>
void print_list(const T* list, const int size);

/*Runs the string tests*/
void test_string();


int main() {

    /*NUMBER TEST*/
	int capacity = 0;
	int size = 0;

	int * arr = allocate<int>(capacity);
	
	cout << "--------------------NUMBER TEST--------------------" << endl;
	for (int i = 0; i < 50; i++) {
		arr = add_entry(arr, i, size, capacity);
		print_list(arr, size);
		cout << "\n";
	}

	for (int j = 50; j > 0 ; j--) {
		arr = remove_entry(arr, j, size, capacity);
		print_list(arr, size);
		cout << "\n";
	}
	delete[] arr;

	/*STRING TEST*/
	cout << "\n--------------------STRING TEST--------------------" << endl;
	test_string();

	return 0;

}

/*Adds a new entry to "list". Doubles the array size if "size" has reached "capacity"
-------------------------------------------------------------------------------------
Preconditions: size < capacity or both equal 0, T points to a valid array which has a block "size" 
               elements and is "capacity" size.
Postconditions: "new_entry" has been added to "list". If size now equals capacity, the contents of 
                "list" have been moved to a new dynamic array with twice the capacity.
*/
template <typename T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity) {

	assert((size >=0) && (capacity >= 0));

	//If size and capacity are 0, we need a special case. We can't multiply capacity to create the 
    //new capacity.
	if ((size == 0) && (capacity == 0)) {
		int null_capacity = 2;
		list = reallocate(list, capacity, size, null_capacity);
		capacity = null_capacity;
	}

	//If size equals capacity, reallocate the list
	if ((size + 1) == capacity) {
		//create a new array with the same contents that is twice the size.
		list = reallocate(list, capacity, size, (capacity * 2));
		capacity = capacity * 2;
	}

	//Put the new entry at the end of the list
	T* end_of_list = list + size; //Doing this because you hate *() notation
	*end_of_list = new_entry;
	size++;

	return list;
}

/*Returns a dynamic array of "capacity" size
--------------------------------------------
Preconditions: capacity > 0
Postconditions: a new array of size "capacity" has been created
*/

template <typename T>
T* allocate(int capacity) {
	assert(capacity >= 0);

	T* new_array = new T[capacity];
	return new_array;
}

/*Reallocates the contents of "src" into a new array of "new_capacity" size
---------------------------------------------------------------------------
Preconditions: "src" points to a valid array with "src_size" elements and "capacity" size; 
               "src_capacity", "src_size", and "new_capacity" > 0
Postconditions: The contents of "src" are now in a new dynamic array of "new_capacity" size
*/
template <typename T>
T* reallocate(T* src, int & src_capacity, int &src_size, int new_capacity) {
	assert((src_capacity >= 0) && (new_capacity >= 0));

	cout << "\nReallocating list capacity from " << src_capacity << " to " << new_capacity << endl;
	T* new_array = allocate<T>(new_capacity);
	
	copy_list(new_array, src, src_size);
	delete[] src;
	return new_array;
}


/*Copies one array(or part of one) into another array
--------------------------------------
Preconditions: "dest" and "src" point to valid arrays; "many_to_copy" is greater than 0, src has 
                a block of "many_to_copy" size elements and dest has a block of "many_to_copy" elements
				available
Postconditions: "many_to_copy" elements have been copied from "dest" to "src"
*/
template <typename T>
void copy_list(T* dest, T* src, int many_to_copy) {
	for (int i = 0; i < many_to_copy; i++) {
		*dest = *src;
		dest++;
		src++;
	}
}

/*Searches "list" for "find_me"
----------------------------------
Preconditions: "list" points to a valid array with "size" many elements && "size" > 0
Postconditions: Everything is untouched
*/
template <typename T>
T* search_entry(T* list, const T& find_me, const int size) {
	T* entry = nullptr;

	for (int i = 0; i < size; i++) {
		if (*list == find_me) {
			entry = list;
			break;
		}
		else {
			list++;
		}
	}

	return entry;
}


template <typename T>
void shift_left(T* list, T* entry, int& size) {
	
	T* walker = entry;

	//Using a for loop was causing too many headaches. You have to pass another argument, but 
	//you don't have to worry about one-off errors.

	//If you don't do it in this order, it won't work out for you
	size--;
	while (walker != (list + size)) {
		T* next_entry = walker + 1;
		*walker = *next_entry;
		walker++;
	}
}

/*Prints "list" to the terminal screen
---------------------------------------
Preconditions: "size" >= 0 and "list" is not nullptr; list has a block of "size" many elements after it
Postconditions: both are unchanged
*/
template <typename T>
void print_list(const T* list, const int size) {
	if (list != nullptr) {
		for (int i = 0; i < size; i++) {
			cout << *list << " ";
			list++;
		}
	}
}

/*Removes the first instance of "delete_me" if it is in "list" and resizes the array
-------------------------------------------------------------------------------------
Preconditions: "list" is intializes and contains "size" elements, "capacity" is the the capacity of 
               "list"
Postconditions: "list" no longer contains "delete_me". "size" is decremented. If "size" has fallen below
                1/4 of "capacity", the list is copied to a new dynamic array of size 1/2 capacity, which
				is returned
*/

template <typename T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity) {
	assert((size >= 0) && (capacity >= 0));

	T* to_delete = search_entry(list, delete_me, size);

	if (to_delete != nullptr) {
		shift_left(list, to_delete, size);

		//if size drops equal or below capacity /4, reallocate list to an array of half capacity
		if (size <= capacity / 4) {
			int new_capacity = capacity / 2;
			list = reallocate(list, capacity, size, new_capacity);
			capacity = new_capacity;
		}
	}
	return list;
}

/*Runs the string tests
---------------------------------------------------
Preconditions: The rest of the program works
Postconditions: A dynamic string array has been created and destroyed.
*/
void test_string() {
	int capacity = 3;
	int size = 0;

	string* list = allocate<string>(capacity);

	list = add_entry<string>(list, "Erika", size, capacity);
	print_list(list, size);
	cout << endl;

	list = add_entry<string>(list, "Red", size, capacity);
	print_list(list, size);
	cout << endl;

	list = add_entry<string>(list, "Bo", size, capacity);
	print_list(list, size);
	cout << endl;

	list = add_entry<string>(list, "Pierson", size, capacity);
	print_list(list, size);
	cout << endl;

	list = add_entry<string>(list, "Maher", size, capacity);
	print_list(list, size);
	cout << endl;

	list = add_entry<string>(list, "Mac", size, capacity);
	print_list(list, size);
	cout << endl;

	list = add_entry<string>(list, "Paula", size, capacity);
	print_list(list, size);
	cout << endl;

	cout << "\nDeleting Erika" << endl;
	list = remove_entry<string>(list, "Erika", size, capacity);
	print_list(list, size);
	cout << endl;

	cout << "\nDeleting Bo" << endl;
	list = remove_entry<string>(list, "Bo", size, capacity);
	print_list(list, size);
	cout << endl;

	cout << "\nDeleting Maher" << endl;
	list = remove_entry<string>(list, "Maher", size, capacity);
	print_list(list, size);
	cout << endl;

	cout << "\nDeleting Pierson" << endl;
	list = remove_entry<string>(list, "Pierson", size, capacity);
	print_list(list, size);
	cout << endl;

	cout << "\nDeleting Red" << endl;
	list = remove_entry<string>(list, "Red", size, capacity);
	print_list(list, size);
	cout << endl;

	delete[]  list;
}
