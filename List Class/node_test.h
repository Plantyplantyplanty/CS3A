#ifndef NODE_TEST_H
#define NODE_TEST_H
#include "Node.h"
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      FUNCTION DEFINITIONS
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
void _test_suite();

template<typename T>
void _test_insert_head(node<T>* &head_ptr);
template<typename T>
void _test_search_and_delete(node<T>* &head, const T key);
template<typename T>
void _test_search_and_insertAfter(node<T>*& head, const T key, const T after);
template<typename T>
void _test_search_and_insertBefore(node<T>*& head, const T key, const T before);

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      FUNCTION DECLARATIONS
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
template<typename T>
void _test_insert_head(node<T>* &head_ptr) {
    for (int i = 0; i < 10; i++) {
        _insert_head(head_ptr, i * 10);
        _print_list(head_ptr);
        cout << endl;
    }
    cout << endl;
}

template<typename T>
void _test_search_and_delete(node<T>* &head, const T key) {
    node<T> * to_delete = _searchList(head, key);
    _deleteNode(head, to_delete);
}

template<typename T>
void _test_search_and_insertAfter(node<T>*& head, const T key, const T after) {
    node<T>* before = _searchList(head, key);
    _insertAfter(head, before, after);
}

template<typename T>
void _test_search_and_insertBefore(node<T>*& head, const T key, const T before) {
    node<T>* after = _searchList(head, key);
    _insertBefore(head, after, before);
}

#endif // NODE_TEST_H
