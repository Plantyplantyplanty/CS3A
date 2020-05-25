#pragma once
#include "Node.h"

template <typename T>
class SortedList {
public:
    /*Creates a sorted list with nothing in it*/
    SortedList(bool order = false, bool unique = true, bool add = true) : _order(order), _unique(unique), _add(add),_head_ptr(nullptr) {};
   
    /*Big Three*/
    ~SortedList();
    SortedList(const SortedList& og);
    SortedList& operator =(const SortedList<T>& og);

    /*Sorted List Iterator*/
    class Iterator {
        friend class SortedList;
    public:
        //Creates an iterator intialized to a passed pointer
        Iterator(node<T>* p = nullptr) :_ptr(p) {}

        Iterator next()                     //return an iterator to the
        {                                   //next location in the list
            return Iterator(_ptr->_next);
        }

        //Returns the item. You can't modify it
        const T& operator *()const {        //dereference operator
            assert(_ptr);
            return _ptr->_item;
        }

        //Returns a non-modifiable pointer to the item
        const T* operator->()const {                    //dereference operator
            assert(_ptr);
            return &(_ptr->_item);
        }

        //Prefix operator
        friend Iterator operator ++(Iterator& it, int unused) {
            Iterator hold;
            hold = it;
            it = it.next();
            return hold;
        }

        //Postfix operator
        Iterator& operator ++() {
            this = this->next();
            return *this;
        }

        /*Boolean Operators*/
        friend bool operator !=(const Iterator& left, const Iterator& right) {
            return left._ptr != right._ptr;
        }


        friend bool operator ==(const Iterator& left, const Iterator& right) {
            return left._ptr == right._ptr;
        }

        /*If the iterator's pointer is null*/
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

    typename SortedList<T>::Iterator insert(T i);
    //insert i. Assume sorted list

    T Delete(typename SortedList<T>::Iterator iMarker);
    //delete node pointed to by iMarker

    void PrintList() const;
    //print the list

    void PrintList_backwards();

    friend ostream& operator <<(ostream& outs, const SortedList<T>& l) {
        return _print_list(l._head_ptr, outs);
    }

    typename SortedList<T>::Iterator search(const T& key);
    //return pointer to node containing key. NULL if not there

    typename SortedList<T>::Iterator prev(SortedList<T>::Iterator iMarker);
    //get the previous node to iMarker
    T& operator[](int index);
    //return the item at index
    typename SortedList<T>::Iterator begin() const { return Iterator(_head_ptr); }
    //return the head of the list
    typename SortedList<T>::Iterator end() const { return Iterator(nullptr); }
    //return the tail of the list

private:
    node<T>* _head_ptr; //The headpointer of the list
    SortedList<T>& copy_og_list(const SortedList<T>& og); //Copies/replaces this list with the passed list
    bool _order; //Ascending or descending
    bool _unique; //If the list should allow duplicates
    bool _add; //use insert_and_add
};

template<typename T>
SortedList<T>::SortedList(const SortedList& og) {
    //Copies the old list into this one
    copy_og_list(og);
}

template<typename T>
SortedList<T>& SortedList<T>::operator =(const SortedList<T>& og) {
    //if the rhs is not "this"
    if (&og != this) {
        _clearList(_head_ptr); //delete this list
        *this = copy_og_list(og); //copy the list of "og" into this list
    }
    return *this;
}

/*Copies the private variables of og into "this"*/
template <typename T>
SortedList<T>& SortedList<T>::copy_og_list(const SortedList<T>& og) {
    _order = og._order;
    _unique = og._unique;
    _add = og._add;
    //Copies the list and assigns the new list's _head_ptr to "this._headptr" 
    _head_ptr = _copyList(og._head_ptr);
    return *this;
}

/*Calls an insert function based on if _add is set or not*/
template <typename T>
typename SortedList<T>::Iterator SortedList<T>::insert(T i) {
    //Returns an iterator "pointing" to the new node inserted wherever it has been sorted
    if (_add) {
        return Iterator(_insertSorted_and_add(_head_ptr, i, _order));
    }
    else {
        return Iterator(_insertSorted(_head_ptr, i, _order));
    }
}

template <typename T>
T SortedList<T>::Delete(typename SortedList<T>::Iterator iMarker) {
    //Returns the item in the deleted node
    return _deleteNode(_head_ptr, iMarker._ptr);
}

template <typename T>
void SortedList<T>::PrintList() const {
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
void SortedList<T>::PrintList_backwards() {
    //goes to the recursive function
    _printList_backwards(_head_ptr);
}

template <typename T>
typename SortedList<T>::Iterator SortedList<T>::search(const T& key) {
    //Returns an Iterator "pointing" to where the key was found
    return Iterator(_searchList(_head_ptr, key));
}

template <typename T>
typename SortedList<T>::Iterator SortedList<T>::prev(SortedList<T>::Iterator iMarker) {
    //Returns an iterator "pointing" to the new node inserted after the marker
      //uses implicit conversion of types as an example
    return _previousNode(_head_ptr, iMarker._ptr);
}

template <typename T>
T& SortedList<T>::operator[](int index) {
    //Returns the item at this index
    return _at(_head_ptr, index);
}

template <typename T>
SortedList<T>::~SortedList() {
    //Deletes the entire list
    _clearList(_head_ptr);
}
