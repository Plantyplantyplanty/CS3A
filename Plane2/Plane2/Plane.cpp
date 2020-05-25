#include "Plane.h"

/*The main driver of the program. Asks if a user wants to reserve, cancel, or quit.
Outputs to terminal. */
void menu(bool** two_d, const int column_length, const int num_rows, int* sizes) {
	int row;
	char column;
	bool seat_value;

	char choice = 'Y';
	while (choice != 'q' && choice != 'Q') {
		cout << "Would you like to reserve a seat(R), cancel(C) or quit(Q)? : ";
		cin >> choice;

		if (choice == 'R' ||choice == 'r') {
			cout << "\nThis is the plane now. There is an X in reserved seats:";
			plane_print(sizes, two_d);
			cout << endl;
			cout << "\nEnter in the row and column you would like to reserve: ";
			cin >> row >> column;

			seat_value = reserve(sizes, two_d, num_rows, row, column);

			if (seat_value == true) {
				cout << "That seat is already reserved. Sorry!\n";
			}
		}
		else if (choice == 'C' || choice == 'c') {
			cout << "\nThis is the plane now. There is an X in reserved seats:";
			plane_print(sizes, two_d);
			cout << endl;
			cout << "\nEnter in the row and column you would like to cancel: ";
			cin >> row >> column;

			seat_value = cancel(sizes, two_d, num_rows, row, column);
			if (seat_value == false) {
				cout << "That seat is not reserved. Sorry!\n";
			}
			else if (seat_value == true) {
				cout << "That seat has been cancelled.\n";
			}
		}
		else {
			"That is not a valid choice! Please re-enter.";
		}
	}
	cout << "\nThis is the plane: ";
	plane_print(sizes, two_d);
	delete[] two_d;
}

/*Reserves a seat at row, column.*/
bool reserve(const int* sizes, bool** rows, const int rows_size, int row, char column) {

	//weird arithmetic to make up for row shifting. Reads the value that is currently there.
	bool seat_value = read(sizes, rows, rows_size, row, (column - 'A') + 1);

	//If the seat is not reserved...
	if (seat_value == false) {
		//Write the character set as "reserved" to that space
		write(sizes, rows, true, rows_size, row, (column - 'A') + 1);
	}

	return seat_value;
}

bool cancel(const int* sizes, bool** rows, const int rows_size, int row, char column) {
	column = toupper(column);
	//weird arithmetic to make up for row shifting. Reads the value that is currently there.
	bool seat_value = read(sizes, rows, rows_size, row, (column - 'A') + 1);

	//If the seat is reserved, make it not reserved
	if (seat_value == true) {
		write(sizes, rows, false, rows_size, row, (column - 'A') + 1);
	}
	return seat_value;
}

//Prints to plane to the terminal
void plane_print(const int* sizes, bool** rows) {
	print(sizes, rows);
}

void plane_initialize(bool** &two_d, const int column_length, const int num_rows, int* &sizes) {
	two_d = allocate2D<bool>(num_rows + 1);; //the array containing the columns of the plane
	sizes = allocate1D<int>(num_rows + 1);//Sizes array is of course as long as two_d minus end 
												//nullptr.
	sizes = initialize_sizes(sizes, num_rows, column_length); // fills the "sizes" array with "column_length" 
	two_d = initialize<bool>(sizes, two_d, num_rows); //All the columns are "column_length" size.
}

/*Intializes the sizes array
--------------------------------------------------------------------------------
Preconditions: column_size >= 0 && size >= 0, sizes containes "size" many blocks
Postconditions: "sizes" is filled with "size" entries of "column_size"*/

int * initialize_sizes(int* sizes, int size, const int column_size) {
	int* initial_sizes = sizes;
	assert(column_size >= 0);

	for (int i = 0; i < size; i++) {
		*sizes = column_size;
		sizes++;
	}

	return initial_sizes;
}