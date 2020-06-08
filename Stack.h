#define _CRTDBG_MAP_ALLOC
#pragma once
#include <iostream>
#include "Node.h"

template<typename T>
class Stack {
public:
    Stack();

    ~Stack();
    Stack(const Stack& og);
    Stack& operator =(const Stack<T>& og);

    class Iterator {
        friend class Stack;
    public:
        Iterator(node<T>* p = nullptr) :_ptr(p) {}

        Iterator next()                     //return an iterator to the
        {                                   //next location in the list
            return Iterator(_ptr->_next);
        }

        /*You should not be able to change items inside the stack*/

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

    typename Stack<T>::Iterator push(const T& item);
    T pop();

    void PrintList() const;
    //print the list

    friend ostream& operator <<(ostream& outs, const Stack<T>& s) {
        return _print_list(s._head_ptr, outs);
    }
    typename Stack<T>::Iterator begin() const { return Iterator(_head_ptr); };
    //return the head of the list

    typename Stack<T>::Iterator end() const { return Iterator(nullptr); };
    //returns end of list

    int size() { return _size; }

    T& operator[](int index);
    T& operator[](int index) const;
    //return the item at index

private:
    node<T>* _head_ptr;
    //Copies/replaces this list with the passed list
    Stack<T>& copy_og_list(const Stack<T>& og);
    int _size;
};


template<typename T>
Stack<T>::Stack() {
    _head_ptr = nullptr;
    _size = 0;
}

template<typename T>
Stack<T>::Stack(const Stack& og) {
    //Copies the old list into this one
    copy_og_list(og);
}

template<typename T>
Stack<T>& Stack<T>::operator =(const Stack<T>& og) {
    if (&og != this) {
        _clearList(_head_ptr); //delete this list
        *this = copy_og_list(og); //copy the list of "og" into this list
    }
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::copy_og_list(const Stack<T>& og) {
    _head_ptr = _copyList(og._head_ptr);
    _size = og._size;
    return *this;
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::push(const T& item) {
    //Returns an iterator "pointing" to the new head of the list
    _size++;
    return Iterator(_insert_head(_head_ptr, item));
}

template <typename T>
T& Stack<T>::operator[](int index) {
    //Returns the item at this index
    return _at(_head_ptr, index);
}

template <typename T>
T& Stack<T>::operator[](int index)const {
    //Returns the item at this index
    return _at(_head_ptr, index);
}


template <typename T>
T Stack<T>::pop() {
    //Returns the item in the deleted node
    --_size;
    T value = _remove_head(_head_ptr);
    return value;
}

template <typename T>
void Stack<T>::PrintList() const {
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
Stack<T>::~Stack() {
    _clearList(_head_ptr);
}