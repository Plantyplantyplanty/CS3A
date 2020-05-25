#include "Lab.h"
#include "2DPointerLibrary.h"

/*Initializes lab and sizes*/
void initialize(int ** &lab, const int num_rows, const int false_value, int * sizes) {
	
	lab = allocate2D<int>(num_rows + 1); //the array containing the columns of the plane
	initialize2D<int>(sizes, lab, num_rows, false_value); //Fills the arrays with -1
}

/*The main driver of the program, logging users in and out until quitting*/
void menu(int ** lab, int * sizes, int num_rows, int false_value) {
	char choice; //What the user wants to do
	int ID_num; //The ID number of the student
	int station; //The station the student is at
	int lab_num; //The lab number the is at

	do {
		cout << "This is the lab now: ";
		lab_print(sizes, lab, false_value);
		cout << "Would you like to login(I), logout(O), or quit(Q)?";
		cin >> choice;

		if (choice == 'I' || choice == 'i') {
			cout << "\nEnter in your ID number: ";
			cin >> ID_num;
			cout << "Enter in your lab #: ";
			cin >> lab_num;
			cout << "Enter in your station #: ";
			cin >> station;

			bool success = login(lab, sizes, num_rows, ID_num, station, lab_num, false_value);
		
			if (success) {
				cout << "\nYou have been logged in to station " << station << ", lab number " << lab_num << endl; 
			}
			else {
				cout << "That station is already taken or invalid\n";
			} 
		
		}
		else if (choice == 'O' || choice == 'o') {
			cout << "\nEnter in your ID number: ";
			cin >> ID_num;
			bool success = logout(lab, sizes, num_rows, ID_num, false_value);

			if (success) {
				cout << "Successfully logged out\n";
			}
			else {
				cout << "No student ID of that number detected\n";
			}
		}
		else if(choice != 'q' && choice != 'Q'){
			cout << "\nInvalid choice\n";
		}
	}while(choice != 'q' && choice != 'Q');
	
	cout << "\nThis is the lab at quitting time: ";
	lab_print (sizes, lab, false_value);
}

/*Logs in to the lab at the requested station, lab*/
bool login(int** lab, const int* sizes, const int num_rows, int ID, const int station, const int lab_num, const int empty_value) {
	//gets the value at (lab_num, station)
	int empty = read(sizes, lab, num_rows, lab_num, station); 

	bool success = false; //Whether the login is successful or not. 

	if (empty == empty_value) { //if the value returned is the value of a station when
		                        //empty
		//Attempt to write the ID to that station
		success = write(sizes, lab, ID, num_rows, lab_num, station);
	}
	return success;
}

/*Logs out of the lab at the requested station, lab*/
bool logout(int** lab, const int* sizes, const int num_rows, int ID, const int false_value) {
	bool logged_out = false; //if the user has been logged out of a station

	const int* sizes_walker = sizes;
	for (int i = 1; i < num_rows+1; i++) {

		//I hate this function definition also. Anyway, once logged_out is true, it is 
		//always true for one run of the function.
		logged_out = lab_logout(lab, num_rows, i, *sizes_walker, sizes, ID, false_value, logged_out);
		cout << endl;
		sizes_walker++;
	}
	return logged_out;
}

//This function definition is terrible. Logs the user out of a lab if their exists within it
bool lab_logout(int ** lab,  const int num_rows, const int row, const int size, const int * sizes, const int ID, const int false_value, bool logged_out) {
	int value;
	for (int j = 1; j < size + 1; j++) {
		value = read(sizes, lab, num_rows, row, j); //Row is the lab number we are on
		if (value == ID) {
			logged_out = true;
			write(sizes, lab, false_value, num_rows, row, j);
		}
	}
	return logged_out;
}

/*Prints the lab to the terminal screen. Uses 2DPointerLibrary's function.*/
void lab_print(const int* sizes, int** lab, const int false_value) {
	print2D(sizes, lab, false_value);
}