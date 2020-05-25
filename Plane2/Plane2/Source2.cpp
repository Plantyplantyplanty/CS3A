/*
 * Author: Marisa Persaud
 * Project: Plane
 * Purpose: Reserve and cancel seats on a plane
 * Notes: I got your permission on any deviations from the expected template. 
 *
 */

#include <iostream>
#include <cassert>
#include "2DPointerLibrary.h"
#include "Plane.h"


int main() {
	int num_rows = 0; //the number of rows on the plane
	bool** two_d = nullptr;
	const int column_length = 4; 
	int* sizes = nullptr;

	cout << "------------------START------------------";

	cout << "\nEnter in the number of rows on the plane: ";
	cin >> num_rows;

	if (num_rows > 0) {
		plane_initialize(two_d,column_length,num_rows,sizes);
		menu(two_d, column_length, num_rows, sizes);
	}
	else {
		cout << "No rows to reserve!\n";
	}
	cout << "\n------------------GOOODBYE-------------------------\n";
	return 0;
}


