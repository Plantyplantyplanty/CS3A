#include "SortedListTest.h"

void test_insert(SortedList<int>& l) {
	for (int i = 0; i < 10; i++) {
		//inserts a random number 0 - 100
		l.insert(i * 10);
	}
}

void s_test_suite(bool ascending) {
	SortedList<int> L(ascending, false);
	test_insert(L);
	cout << "Adding to List: " << endl;
	
	cout << "Printing List: " << endl;
	cout << L;
	cout << endl << "Copying List " << endl;
	SortedList<int> P(L);
	cout << endl << "Searching list and deleting 90...." << endl;
	s_test_search_and_delete(L, 90);
	cout << "Printing List: " << endl;
	cout << L;
	cout << endl << "Searching list and deleting 0...." << endl;
	s_test_search_and_delete(L, 0);
	cout << "Printing List: " << endl;
	cout << L;
	cout << endl << "Searching list and deleting 40...." << endl;
	s_test_search_and_delete(L, 40);
	cout << "Printing List: " << endl;
	cout << L;
	cout << endl << "The First node: " << *(L.begin());
	cout << endl << "Printing copy of original before changes: " << endl;
	cout << P;
	cout << endl << "Inserting sorted 45 in List Copy" << endl;
	P.insert(45);
	cout << "Printing List Copy: " << endl;
	cout << P;
	cout << endl << "Inserting sorted 100 in List Copy" << endl;
	P.insert(100);
	cout << "Printing List Copy: " << endl;
	cout << P;
	cout << endl << "Inserting sorted -1 in List Copy" << endl;
	P.insert(-1);
	cout << "Printing List Copy: " << endl;
	cout << P;
	cout << endl << "P = L" << endl;
	P = L;
	cout << P << endl << L << endl;
	P.insert(10);
	cout << "After insert 10: ";
	cout << endl << P << endl << L << endl;
	cout << endl;
	cout << "Printing List Backward: " << endl;
	P.PrintList_backwards();
	cout << endl;
}