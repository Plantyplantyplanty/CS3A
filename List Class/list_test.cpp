#include "list_test.h"
string John = "John";
string Jacob = "Jacob";
string cat = "cat";
string monster = "monster";
string fraud = "fraud";
string bingo = "bingo";
string boing = "boing";
string Tina = "Tina";
string Taylor = "Taylor";

void test_insert_head(List<string> &l) {
        l.insert_head(John);
		l.insert_head(Jacob);
		l.insert_head(cat);
		l.insert_head(boing);
		l.insert_head(Tina);
		l.insert_head(Taylor);
}
void test_suite() {
    List<string> L;

    cout << "Adding to List: " << endl;
    test_insert_head(L);
    cout << "Printing List: " << endl;
    cout << L;
    cout << endl << "Copying List " << endl;
    List<string> P(L);
    cout << endl << "Searching list and deleting cat...." << endl;
    test_search_and_delete(L, cat);
    cout << "Printing List: " << endl;
    cout << L;
    cout << endl << "Searching list and deleting Taylor...." << endl;
    test_search_and_delete(L, Taylor);
    cout << "Printing List: " << endl;
    cout << L;
    cout << endl << "Searching list and deleting John...." << endl;
    test_search_and_delete(L, John);
    cout << "Printing List: " << endl;
    cout << L;
	/*monster fraud bingo*/
	cout << endl << "Inserting monster after boing....";
	test_search_and_insertAfter(L, boing, monster);
	cout << endl << "Inserting fraud after Tina....";
	test_search_and_insertAfter(L, Tina, fraud);
	cout << endl << "Inserting bingo after Jacob...." << endl;
	test_search_and_insertAfter(L, Jacob, bingo);
	cout << "Printing List: " << endl;
	cout << L << endl;
	cout << "Inserting Taylor before monster...." << endl;
	//Tests the ->. All other iterator functions are tested elsewhere.
	List<string>::Iterator it = test_search_and_insertBefore(L, monster, Taylor);
	cout << "Taylor's length: " << it->length() << endl;
	cout << "Printing List: " << endl;
	cout << L;
	cout << endl << "Inserting boing before Tina...." << endl;
	test_search_and_insertBefore(L, Tina, boing);
	cout << "Printing List: " << endl;
	cout << L;
	cout << endl << "The First node: " << *(L.begin());
	cout << endl << "Printing copy of original before changes: " << endl;
	cout << P;
	/*
	cout << endl << "Inserting sorted 45 in List Copy" << endl;
	P.insertSorted(45, false);
	cout << "Printing List Copy: " << endl;
	cout << P;
	cout << endl << "Inserting sorted 100 in List Copy" << endl;
	P.insertSorted(100, false);
	cout << "Printing List Copy: " << endl;
	cout << P;
	cout << endl << "Inserting sorted -1 in List Copy" << endl;
	P.insertSorted(-1, false);*/
	cout << "Printing List Copy: " << endl;
	cout << P;
	cout << endl << "P = L" << endl;
	P = L;
	cout << P << endl << L << endl;
	P.insert_head(cat);
	cout << "After inserthead cat: ";
	cout << endl << P << endl << L << endl;
	cout << endl; 
	cout << "Printing List Backward: " << endl;
	P.PrintList_backwards();
	cout << endl;
}