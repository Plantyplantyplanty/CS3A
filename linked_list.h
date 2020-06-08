#define _CRTDBG_MAP_ALLOC
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "Node.h"

template <typename T>
class List {
public:
    List();

    ~List();
    List(const List& og);
    List& operator =(const List<T>& og);

    class Iterator {
        friend class List;
    public:
        Iterator(node<T>* p = nullptr) :_ptr(p) {}

        Iterator next()                     //return an iterator to the
        {
            assert(_ptr != nullptr);              //next location in the list
            return Iterator(_ptr->_next);
        }


        T& operator *() {                    //dereference operator
            assert(_ptr);
            return _ptr->_item;
        }

        T* operator->() {                    //dereference operator
            assert(_ptr);
            return &(_ptr->_item);
        }

        const T* operator->()const {                    //dereference operator
            assert(_ptr);
            return &(_ptr->_item);
        }

        const T& operator *()const {        //dereference operator
            assert(_ptr);
            return _ptr->_item;
        }

        friend Iterator operator ++(Iterator& it, int unused) {
            Iterator hold;
            hold = it;
            it = it.next();
            return hold;
        }

        Iterator& operator ++() {
            this = this->next();
            return *this;
        }


        friend bool operator !=(const Iterator& left, const Iterator& right) {
            return left._ptr != right._ptr;
        }


        friend bool operator ==(const Iterator& left, const Iterator& right) {
            return left._ptr == right._ptr;
        }

        bool ifNull() {
            if (_ptr == nullptr) {
                return true;
            }
            else
                return false;
        }
    private:
        node<T>* _ptr;
    };

    typename List<T>::Iterator insert_head(const T& item);
    //insert i at the head of list
    typename List<T>::Iterator insertAfter(T i, List<T>::Iterator iMarker);
    //insert i after iMarker
    typename List<T>::Iterator insertBefore(T i, List<T>::Iterator iMarker);
    //insert i before iMarker
    typename List<T>::Iterator insertSorted(T i, bool ascending = true);
    //insert i. Assume sorted list

    T Delete(typename List<T>::Iterator iMarker);
    //delete node pointed to by iMarker

    T remove_head();

    void PrintList() const;
    //print the list
    void PrintList_backwards();

    friend ostream& operator <<(ostream& outs,
        const List<T>& l) {
        return _print_list(l._head_ptr, outs);
    }

    typename List<T>::Iterator search(const T& key);
    //return pointer to node containing key. NULL if not there

    typename List<T>::Iterator prev(List<T>::Iterator iMarker);
    //get the previous node to iMarker
    T& operator[](int index);
    //return the item at index
    typename List<T>::Iterator begin() const { return Iterator(_head_ptr); };
    //return the head of the list
    typename List<T>::Iterator end() const;
    //return the tail of the list

private:
    node<T>* _head_ptr;
    //Copies/replaces this list with the passed list
    List<T>& copy_og_list(const List<T>& og);
};


template<typename T>
List<T>::List() {
    _head_ptr = nullptr;
}

template<typename T>
List<T>::List(const List& og) {
    //Copies the old list into this one
    copy_og_list(og);
}

template<typename T>
List<T>& List<T>::operator =(const List<T>& og) {
    if (&og != this) {
        _clearList(_head_ptr); //delete this list
        *this = copy_og_list(og); //copy the list of "og" into this list
    }
    return *this;
}

template <typename T>
List<T>& List<T>::copy_og_list(const List<T>& og) {
    _head_ptr = _copyList(og._head_ptr);
    return *this;
}

template <typename T>
typename List<T>::Iterator List<T>::insert_head(const T& item) {
    //Returns an iterator "pointing" to the new head of the list
    return Iterator(_insert_head(_head_ptr, item));
}

template <typename T>
typename List<T>::Iterator List<T>::insertAfter(T i, List<T>::Iterator iMarker) {
    //Returns an iterator "pointing" to the new node inserted after the marker
    return Iterator(_insertAfter(_head_ptr, iMarker._ptr, i));
}

template <typename T>
typename List<T>::Iterator List<T>::insertBefore(T i, List<T>::Iterator iMarker) {
    //Returns an iterator "pointing" to the new node inserted before the marker
    return _insertBefore(_head_ptr, iMarker._ptr, i);
}

template <typename T>
typename List<T>::Iterator List<T>::insertSorted(T i, bool ascending) {
    //Returns an iterator "pointing" to the new node inserted wherever it has been sorted
    return Iterator(_insertSorted(_head_ptr, i, ascending));
}

template <typename T>
T List<T>::Delete(typename List<T>::Iterator iMarker) {
    //Returns the item in the deleted node
    return _deleteNode(_head_ptr, iMarker._ptr);
}

template <typename T>
T List<T>::remove_head() {
    //Returns the item in the deleted node
    T value = _remove_head(_head_ptr);
    return value;
}

template <typename T>
void List<T>::PrintList() const {
    if (_head_ptr != nullptr) {
        node<T>* head = _head_ptr;
        while (head->_next != nullptr) {
            cout << *head;
            head = head->_next;
        }
        cout << *head;
    }
}

template <typename T>
void List<T>::PrintList_backwards() {
    _printList_backwards(_head_ptr);
}

template <typename T>
typename List<T>::Iterator List<T>::search(const T& key) {
    //Returns an Iterator "pointing" to where the key was found
    return Iterator(_searchList(_head_ptr, key));
}

template <typename T>
typename List<T>::Iterator List<T>::prev(List<T>::Iterator iMarker) {
    //Returns an iterator "pointing" to the new node inserted after the marker
      //uses implicit conversion of types as an example
    return _previousNode(_head_ptr, iMarker._ptr);
}

template <typename T>
T& List<T>::operator[](int index) {
    //Returns the item at this index
    return _at(_head_ptr, index);
}

template <typename T>
typename List<T>::Iterator List<T>::end() const {
    //The end is a nullptr
    return Iterator(nullptr);
}

template <typename T>
List<T>::~List() {
    _clearList(_head_ptr);
}
#endif // LINKED_LIST_H