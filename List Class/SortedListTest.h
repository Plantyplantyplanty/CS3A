#pragma once
#include "SortedList.h"

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      FUNCTION DEFINITIONS
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
void s_test_suite(bool ascending);
void test_insert(SortedList<int>& l);

template<typename T>
void s_test_search_and_delete(SortedList<T>& l, const T key);
template<typename T>
void test_insert(SortedList<T>& l, const T key);
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      FUNCTION DECLARATIONS
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template<typename T>
void s_test_search_and_delete(SortedList<T>& l, const T key) {
	typename SortedList<T>::Iterator to_delete = l.search(key);
	l.Delete(to_delete);
}

template<typename T>
void test_insert(SortedList<T>& l, const T key) {
	l.insert(key);
}

#pragma once
