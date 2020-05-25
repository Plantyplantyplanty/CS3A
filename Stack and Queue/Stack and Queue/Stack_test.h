#ifndef STACK_TEST_H
#define STACK_TEST_H

#include "Stack.h"
using namespace std;

//Main driver for testing
void test_stack();
//Intializes a string stack
void initialize_string_stack(Stack<string>& s);
void intialize_int_stack(Stack<int>& s);

template<typename T>
void pop_stack(Stack<T>& s) {
	while (s.size() > 0) {
		cout << endl << "Popping " << s.pop();
		cout << endl << "The stack now: \n" << s;
	}
}

template<typename T>
void print_stack(Stack<T> s) {
	typename Stack<T>::Iterator it = s.begin();
	for (it; it != nullptr; it++) {
		cout << *it << " ";
	}
	cout << endl << endl;
}
#endif