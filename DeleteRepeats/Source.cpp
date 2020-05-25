#include <iostream>
#include <cassert>
using namespace std;

/*Deletes the repeats in a set of user-given characters
/*
 * Author: Marisa Persaud
 * Project: Delete Repeats
 * Purpose: Delete repeats in a given character array while leaving the array's order intact. 
 */

//FUNCTIONS PROTOTYPES
//--------------------

/*Creates an array of type T with user input*/
template<typename T>
void initialize(T * toFill, int size);

/*Prints an array of template type T to the terminal*/
template<typename T>
void print(T * toPrint, int size);

/*Deletes repeated chars in a char array*/
template<typename T>
int delete_repeats(T * container, int size);

/*Fills an array of template type T with "size" elements*/
template<typename T>
void append(T * container, T * new_array, int size);

/*Finds if key is between initial and initial+counter. */
template<typename T>
bool find(T key, T* initial, int counter);

//MAIN
//--------------------
int main() {
	int size;		 //The size of the array
	char * final_answer = NULL;     //Will hold the final array

	cout << "Enter in the number of elements: ";
	cin >> size; 
	
	char * container = new char[size]; //Holds the initial array of characters

	cout << "Enter in " << size << " characters:\n";

	if (size > 0) {
		initialize(container, size);

		cout << "You entered in: \n";
		print(container, size);
		cout << endl;

		size = delete_repeats(container, size); //returns the size of "container" now taken up with the array of unique
												//characters
		final_answer = new char[size];          //initializes a brand-new array of the size needed to store the new
												//array of unique characters
		append(container, final_answer, size);  //fills the new array
		delete[] container;                     //We don't need this anymore. It's just wasting space now             

		cout << "\nYour array without repeats:\n";
		print(final_answer, size);
		cout << endl;

		delete[] final_answer;  //The compiler is about to do this anyway, but good practice I guess?
	}
	else {
		cout << "\n0 characters requested. Exiting...";
	}
	return 0;
}

//FUNCTION DEFINITIONS
//--------------------
/*Creates an array of type T with user input
------------------------------------------
 Preconditions: toFill is at least the size of "size"
 Postconditions: toFill is full of "size" elements
*/
template<typename T>
void initialize(T* toFill, int size) {
	assert(toFill != nullptr);
	for (int i = 0; i < size; i++) {
		cin >> *toFill;
		toFill++;
	}
}
/*Prints an array of template type T to the terminal
------------------------------------------
 Preconditions: toPrint is full until "size", and at least "size" elements large
 Postconditions: Both elements are untouched.*/
template<typename T>
void print(T * toPrint, int size) {
	assert(toPrint != nullptr);
	for (int i = 0; i < size; i++) {
		cout << *toPrint << " ";
		toPrint++;
	}
	
}

/*Deletes repeated chars in a char array
------------------------------------------
Preconditions: container is full of "size" elements, and "size" <= to the amount of elements in container
Postconditions: 1.)container is full until return value
				2.)container has no repeats for the size specified by the return value.
				3.)After the size returned are the remnants of the old array
Returns: The number of elements which now store all unrepeated characters in container.
*/
template<typename T>
int delete_repeats(T * container, int size) {
	/*Ok, we could brute force this by searching every element of the array against every other and deleting the 
	repeats, or we could loose the ordering by sorting the array and deleting the extras. So to compromise, 
	we're going to search every element of the original array against the array of answers, which is intialized with 
	the first  character of the intial array, and ends up  containing all unique chars in their original order. If an
	element is not in there when the array of answers is searched for it, it gets added. Bear with me.
	
	...Extra note: Ryan(husband) suggested that my algorithm could be done in place. Now I have to see if I can do it.
	(the answer is yes). So we're going to use the first part of the original array as storage for unique 
	values while iterating through the rest. This will make the code more confusing to read, though.
	*/
	assert(container != nullptr);
	T* initial = container;          //The beginning element of container
	int counter = 1;                 //the number of elements in the part of container with the answers
	bool in_answer_array = false;    //if the selected character is in the answer array

	//iterating over the entire array
	for (int i = 0; i < size; i++) {

		//Find if the (element of container) is between 0 and counter elements of container(where the answer is 
		//being stored).
		if (!find(*container, initial, counter)) { 
			//if it's NOT in the part of the array with the answer, add it
			*(initial + counter) = *container;
	  		counter++;
		} 
		container++;
	}
	//I was just sending initial and counter over to "print" directly, and that works. But I think you want me to 
	//create a new array and print that, so that's in the final version.
	return counter;
}


/*Fills a char array with "size" elements
------------------------------------------
Preconditions: container is full to  "size" elements, and "size" <= to the amount of elements in container & new_array
Postconditions: new_array is full to "size" size with the 0:size-1 elements of container
*/
template<typename T>
void append(T * container, T * new_array, int size) {
	assert((container != nullptr) && (new_array != nullptr));
	for (int i = 0; i < size; i++) {
		*new_array = *container;
		new_array++;
		container++;
	}
}

/*Finds if key is between initial and initial+counter.
-------------------------------------------------------------------------------------------------------------
Preconditions: Initial is filled up to key. Counter is initialized and >=0. Key is of the same type as initial
Postconditions: Everything is untouched. Maybe it should be const? Think about it.
*/
template<typename T>
bool find(T key, T* initial, int counter) {
	assert(initial != nullptr);

	bool in_answer_array = false;
	T* walker = initial;

	//Search the currently selected element of the original array against the known unique characters stored in 
	//the original array
	for (int j = 0; j < counter; j++) {
		if (key == *walker) {
			in_answer_array = true;
			break;
		}
		walker++;
	}
	return in_answer_array;
}


/* Old version

Ok, we could brute force this by searching every element of the array against every other and deleting the 
	repeats, or we could loose the ordering by sorting the array and deleting the extras. So to compromise, 
	we're going to search every element of the original array against the array of answers, which is intialized with 
	the first  character of the intial array, and ends up  containing all unique chars in their original order. If an
	element is not in there when the array of answers is searched for it, it gets added. Bear with me.

	...Extra note: Husband suggested that my algorithm could be done in place. Now I have to see if he's right.
	So we're going to use the first part of the original array as storage while iterating through the rest.
	

	//The array of answers
T answer_array = new char[size]; //at most, we have no repeats. So this array of answers 
								 //needs to be as big as the original array.
*answer_array = *container;      //initialize with the first element of the original array
char* walker = answer_array;     //will walk over answer_array

int counter = 1;                 //the number of elements in the answer array
bool in_answer_array = false;    //if the selected character is in the answer array

//iterating over the entire original array
for (int i = 0; i < size; i++) {
	in_answer_array = false;

	//Search the currently selected element of the original array against the entire answer array
	for (int j = 0; j < counter; j++) {
		if (*container == *walker) {
			in_answer_array = true;
			break;
		}
		walker++;
	}

	//if it's not in the answer array already, add it 
	if (!in_answer_array) {
		*(answer_array + counter) = *container;
		counter++;
	}
	container++;
	walker = answer_array;
}

print(answer_array, counter);
*/