#pragma once

#include "Queue.h"
using namespace std;

//Main driver for testing
void test_queue();
//Intializes a string stack
void initialize_string_queue(Queue<string>& q);
void intialize_int_queue(Queue<int>& q);

template<typename T>
void pop_queue(Queue<T>& q){
	while (q.size() > 0) {
		cout << endl << "Popping " << q.pop();
		cout << endl << "The queue is now: \n" << q;
	}
}

template<typename T>
void print_queue(Queue<T> q) {
	typename Queue<T>::Iterator it = q.begin();
	typename Queue<T>::Iterator null;

	for (it; it != null; it++) {
		cout << *it << " ";
	}
	cout << endl << endl;
}
