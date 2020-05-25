#include "Lab.h"
#include <iostream>
using namespace std;

/*
 * Author: Marisa Persaud
 * Project: Lab
 * Purpose: Logs you in and out of a lab
 * Notes: I did my best to run an changes in implementation by you before making them.
          I can't bear to do my usual commenting style on all of these programs. I hope
          that's ok...
 **/

int main() { 
    const int num_rows = 4; //from the book
	int sizes[num_rows] = { 4, 5, 3, 2 }; //from the book
	int false_value = -1; //the value which indicates that the spot is empty.
	int** lab = nullptr;

    initialize(lab, num_rows, false_value, sizes); //sets up the lab.
	menu(lab, sizes, num_rows, false_value); //asks the user what they want
	return 0;
}