#include <iostream>
#include "MCounter.h"
using namespace std;

/*
 * Author: Marisa Persaud
 * Project: Mom's Counter
 * Purpose: A counter from 0-9999, which overflows when it is greater but can be reset.
 * Notes: None
 */


void test_MCounter();
//Tests the counter class

void display_count(MCounter counter);
//Displays the counter. Displays "ERROR" if it has overflowed.

int main() {
	test_MCounter();
	return 0;
}

//Tests the counter class with a menu
void test_MCounter() {
	MCounter counter;
	char choice;
	
	do {
		display_count(counter);
		cout << "[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it" << endl;
		cin >> choice;
		switch (choice) {
		case 'A':
		case'a':
			counter.add_1000();
			break;
		case 'S':
		case's':
			counter.add_100();
			break;
		case 'D':
		case 'd':
			counter.add_10();
			break;
		case 'F':
		case 'f':
			counter.add_1();
			break;
		case 'R':
		case 'r':
			counter.reset();
			break;
		}
	} while (choice != 'x' && choice != 'X');

	cout << endl << endl << "======================" << endl;
}

//Displays the counter. Displays "ERROR" if it has overflowed.
void display_count(MCounter counter) {
	bool error = bool(counter.error());
	if (!error) {
		cout << "-------" << endl;
		//cout << counter.count() << endl;
		printf("|%04d|", counter.count()); //Formats the count with up to 4 zeros in front of 
		                                   //it
		cout << "\n-------" << endl;
	}
	else {
		cout << "|ERROR|" << endl;
	}
}