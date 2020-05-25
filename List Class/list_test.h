#ifndef LIST_TEST_H
#define LIST_TEST_H

#include <string>
#include "linked_list.h"

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      FUNCTION DEFINITIONS
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
void test_insert_head(List<string> &l);
void test_suite();

template<typename T>
void test_search_and_delete(List<T> &l, const T key);

template<typename T>
void test_search_and_insertAfter(List<T> &l, const T key, const T insert);

template<typename T>
typename List<T>::Iterator test_search_and_insertBefore(List<T> &l, const T key, const T before);
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      FUNCTION DECLARATIONS
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template<typename T>
void test_search_and_delete(List<T>& l, const T key) {
	typename List<T>::Iterator to_delete = l.search(key);
	l.Delete(to_delete);
}

template<typename T>
void test_search_and_insertAfter(List<T>& l, const T key, const T insert) {
	typename List<T>::Iterator insertAfter = l.search(key);
	l.insertAfter(insert, insertAfter);
}

template<typename T>
typename List<T>::Iterator test_search_and_insertBefore(List<T> &l, const T key, const T before) {
	typename List<T>::Iterator after = l.search(key);
	return l.insertBefore(before, after);
}
#endif // LIST_TEST_H
#pragma once
