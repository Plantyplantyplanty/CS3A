#include "node_test.h"
#include "node.h"

void _test_suite() {
	node<int>* head_pointer = nullptr;
	node<int>* second = nullptr;
	node<int>* to_delete = nullptr;
	cout << "Adding to List: " << endl;
	_test_insert_head(head_pointer);
	cout << "Printing List: " << endl;
	_print_list(head_pointer);
	cout << endl << "Copying List " << endl;
	second = _copyList(head_pointer);
	cout << endl << "Searching list and deleting 90...." << endl;
	_test_search_and_delete(head_pointer, 90);
	cout << "Printing List: " << endl;
	_print_list(head_pointer);
	cout << endl << "Searching list and deleting 0...." << endl;
	_test_search_and_delete(head_pointer, 0);
	cout << "Printing List: " << endl;
	_print_list(head_pointer);
	cout << endl << "Searching list and deleting 40...." << endl;
	_test_search_and_delete(head_pointer, 40);
	cout << "Printing List: " << endl;
	_print_list(head_pointer);
	cout << "Inserting 999 after 50...." << endl;
	_test_search_and_insertAfter(head_pointer, 50, 999);
	cout << "Inserting 999 before 80...." << endl;
	_test_search_and_insertBefore(head_pointer, 80, 999);
	cout << "Printing List: " << endl;
	_print_list(head_pointer);
	cout << endl << "Inserting 999 before 10...." << endl;
	_test_search_and_insertBefore(head_pointer, 10, 999);
	cout << "Printing List: " << endl;
	_print_list(head_pointer);
	cout << endl << "The last node: " << *(LastNode(head_pointer));
	cout << endl << "Printing copy of original before changes: " << endl;
	_print_list(second);
	cout << endl << "Where 45 goes in List Copy: " << (*(_whereThisGoes(second, 45, false)));
	cout << endl << "Where -1 goes in List Copy: " << (*(_whereThisGoes(second, -1, false)));
	cout << endl << "Inserting sorted 45 in List Copy" << endl;
	_insertSorted(second, 45, false);
	cout << "Printing List Copy: " << endl;
	_print_list(second);
	cout << endl << "Inserting sorted 100 in List Copy" << endl;
	_insertSorted(second, 100, false);
	cout << "Printing List Copy: " << endl;
	_print_list(second);
	cout << endl << "Inserting sorted -1 in List Copy" << endl;
	_insertSorted(second, -1, false);
	cout << "Printing List Copy: " << endl;
	_print_list(second);
	cout << endl << "Clearing List... " << endl;
	_clearList(head_pointer);
	_clearList(second);
	cout << endl;
}

