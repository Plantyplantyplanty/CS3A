#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cassert>
using namespace std;

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//     STRUCT DEFINITION
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
template <typename T>
struct node {
    T _item;
    node<T>* _next;

    node(const T& item = T(), node<T>* next = nullptr) :
        _item(item), _next(next) {}

    friend ostream& operator<<(ostream& outs, const node<T> n) {
        outs << "[" << n._item << "]";
        return outs;
    }
};

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      FUNCTION DECLARATIONS
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
template<typename T>
node<T>* _insert_head(node<T>*& head_ptr, const T& item);

template<typename T>
ostream& _print_list(node<T>* head_ptr, ostream& outs = cout);

template <typename T>
void _printList_backwards(node<T>* head);            //recursive fun! :)

template <typename T>
node<T>* _searchList(node<T>* head, T key);
// return ptr to key or NULL

template <typename T>
node<T>* _insertAfter(node<T>*& head, node<T>* afterThis, T insertThis);
//insert after ptr

template<typename T>
T _remove_head(node<T>*& head);

template <typename T>
node<T>* _insertBefore(node<T>*& head, node<T>* beforeThis, T insertThis);
//insert before ptr

template <typename T>
node<T>* _previousNode(node<T>* head, node<T>* prevToThis);
//ptr to previous node

template <typename T>
T _deleteNode(node<T>*& head, node<T>* deleteThis);
//delete, return item

template <typename T>
node<T>* _copyList(node<T>* head);
//duplicate the list...

template <typename T>
void _clearList(node<T>*& head);
//delete all the nodes

template <typename T>
T& _at(node<T>* head, int pos);
//_item at this position

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename T>
node<T>* _insertSorted(node<T>*& head, T item, bool ascending = true);

template <typename T>
node<T>* InsertSorted_and_add(node<T>*& head, //insert or add if a dup
    T item,
    bool ascending = true);

template <typename T>
node<T>* _whereThisGoes(node<T>* head, T item, bool ascending = true);
template <typename T>
node<T>* LastNode(node<T>* head);            //Last Node in the list

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      FUNCTION DEFINITIONS
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename T>
void _printList_backwards(node<T>* head) {
    if (head->_next != nullptr) {
        _printList_backwards(head->_next);
    }
    cout << *head << "<-";
}
template<typename T>
node<T>* _insert_head(node<T>*& head_ptr, const T& item) {
    //insert the item at the head of the list: make it the first j
    //      link in the chain.

    //1: create a new node:
    node<T>* temp = new node<T>(item);
    //2. point (the next field of) this new node to where head is pointing to
    temp->_next = head_ptr;

    //3. point head to this new node:
    head_ptr = temp;

    return head_ptr;
}

/*Inserts a new node with "insertThis" as the key after "afterThis"
-------------------------------------------------------------------
Preconditions: "afterThis" is in the list, and "head" is not nullptr
Postconditions: The description
*/
template <typename T>
node<T>* _insertAfter(node<T>*& head, node<T>* afterThis, T insertThis) {
    node<T>* to_insert;

    if (head == nullptr && afterThis == nullptr) {
        to_insert = _insert_head(head, insertThis);
    }
    else {
        assert(afterThis != nullptr);
        //Create a new node with the item and the pointer to the next object held in "afterThis"
        to_insert = new node<T>(insertThis, afterThis->_next);
        //assign the previous link's "next" to the new node
        afterThis->_next = to_insert;
    }
    return to_insert;
}

/*Inserts a new node with "insertThis" as the key before "beforeThis"
---------------------------------------------------------------------
Preconditions: "head" is not nullptr and "beforeThis" is in the list, is not head
Postconditions: description
*/
template <typename T>
node<T>* _insertBefore(node<T>*& head, node<T>* beforeThis, T insertThis) {
    node<T>* to_insert;

    if (head == beforeThis) {
        to_insert = _insert_head(head, insertThis);
    }
    else {
        assert(head != nullptr && beforeThis != nullptr);
        node<T>* beforeBeforeThis = _previousNode(head, beforeThis);
        to_insert = _insertAfter(head, beforeBeforeThis, insertThis);
    }

    return to_insert;
}

/*Gets the node previous to "prevToThis"
----------------------------------------
Preconditions: head is not nullptr, prevToThis is not null and is in the list
Postconditons: everything remains the same; returns "nullptr" if node is not found
*/
template <typename T>
node<T>* _previousNode(node<T>* head, node<T>* prevToThis) {
    assert(head != nullptr && prevToThis != nullptr);
    node<T>* beforePrev = head;

    if (head != nullptr) {
        //Checks that we have not fallen off the list and that the next value is not equal
        //to what we're looking for
        while (beforePrev != nullptr && beforePrev->_next != prevToThis) {
            beforePrev = beforePrev->_next;
        }
    }
    return beforePrev;
}

/*Deletes the passed node from the list/dynamic memory
----------------------------------------
Preconditions: head is not nullptr, deleteThis is not null and is in the list
Postconditons: description
*/
template <typename T>
T _deleteNode(node<T>*& head, node<T>* deleteThis) {
    assert(head != nullptr && deleteThis != nullptr);

    T to_return; //return value

    if (deleteThis == head) {
        to_return = _remove_head(head);
    }
    else {
        //Get the previous node
        node<T>* prevDelete = _previousNode(head, deleteThis);
        assert(prevDelete != nullptr); //although this should be impossible


        prevDelete->_next = deleteThis->_next;
        to_return = deleteThis->_item;

        delete deleteThis;
    }
    return to_return;
}

/*Deletes the first item and reallocates head
----------------------------------------
Preconditions: head is not nullptr
Postconditons: description
*/
template<typename T>
T _remove_head(node<T>*& head) {
    assert(head != nullptr); //If we don't assert, there is nothing to return

    //Save the pointer to the head
    node<T>* to_delete = head;
    //What we're returning
    T item = head->_item;

    head = head->_next;
    //delete to_delete;
    delete to_delete;

    return item;
}

template<typename T>
ostream& _print_list(node<T>* head_ptr, ostream& outs) {
    outs << "H->";
    for (node<T>* w = head_ptr; w != nullptr; w = w->_next) {
        outs << *w << "->";
    }
    outs << "|||";
    return outs;
}

/*Searches the list for the key. If not found, returns nullptr */
template <typename T>
node<T>* _searchList(node<T>* head, T key) {
    node<T>* address = nullptr;

    if (head != nullptr) {
        node<T>* temp = head;

        //until we've reached the end of the list, keep seeing if this item holds the key
        while (temp != nullptr) {
            if (temp->_item == key) {
                address = temp;
                break;
            }
            temp = temp->_next;
        }
    }
    return address;
}

/*Copies the list into a new list pointing to "head"
----------------------------------------
Postconditons: description
*/
template <typename T>
node<T>* _copyList(node<T>* head) {
    node<T>* new_head;
    if (head != nullptr) {

        //Copy the previous head ptr into a new dynamic variable and assign it
        new_head = new node<T>(*head);

        //Copy the list
        node<T>* temp = new_head;

        //Until we have gotten to the end of the list...
        while (temp->_next != nullptr) {
            //Create a new node which is a copy of the next node
            node<T>* new_node = new node <T>(*(temp->_next));
            //Join it to the previous node
            temp->_next = new_node;
            //Go to the next item
            temp = new_node;
        }
    }
    else {
        //There's nothing in the original head! So now there is nothing in here. 
        new_head = nullptr;
    }
    return new_head;

}

/*Deletes the entire list*/
template <typename T>
void _clearList(node<T>*& head) {
    if (head != nullptr) {
        node<T>* to_delete = head;
        while ((to_delete->_next) != nullptr) {
            node<T>* holder = to_delete->_next;
            delete to_delete;
            to_delete = holder;
        }
        delete to_delete;
    }
}

/*Returns the value at "pos"; uses array notation
----------------------------------------
Preconditions: head is not nullptr, pos is "within bounds" of the list
Postconditons: The list is unchanged
*/
template <typename T>
T& _at(node<T>* head, int pos) {
    assert(head != nullptr);

    for (int i = 0; i <= pos; i++) {
        head = head->_next;
        assert(head != nullptr);
    }

    return head->_item;
}

template <typename T>
node<T>* _insertSorted(node<T>*& head, T item, bool ascending) {
    node<T>* to_return = nullptr;

    //This is double-protected against head being nullptr, but I'm ok with that
    if (head != nullptr) {
        node<T>* follower = nullptr; //contains the node previous to "checker"

        //Return the node before where the item goes
        if (ascending) {
            follower = _whereThisGoes(head, item);
        }
        if (!ascending) {
            follower = _whereThisGoes(head, item, false);
        }

        //Insert the item
        if (follower == nullptr) {
            to_return = _insert_head(head, item);
        }
        else {
            to_return = _insertAfter(head, follower, item);
        }
    }
    else {
        to_return = _insert_head(head, item);
    }
    return to_return;
}

/*Returns the address of what item should be before this in a sorted list.
Returns null if head = nullptr or if it should be inserted before head*/
template <typename T>
node<T>* _whereThisGoes(node<T>* head, T item, bool ascending) {
    node<T>* to_return;
    node<T>* checker = nullptr;

    if (head != nullptr) {
        //to_return = head;
        checker = head;
        node<T>* follower = nullptr;

        if (ascending) {
            while (checker != nullptr && checker->_item <= item) {
                follower = checker;
                checker = checker->_next;
            }
            /*while (to_return->_item <= item && to_return->_next != nullptr) {
                     to_return = to_return->_next;
            }*/
        }
        if (!ascending) {
            while (checker != nullptr && checker->_item >= item) {
                follower = checker;
                checker = checker->_next;
            }
            /*while (to_return->_item >= item && to_return->_next != nullptr) {
                    to_return = to_return->_next;
            }*/
        }
        to_return = follower;
    }
    else {
        to_return = nullptr;
    }
    return to_return;
}

/*Returns the last node in the list. Returns null if head is null*/
template <typename T>
node<T>* LastNode(node<T>* head) {

    node<T>* walker = head;
    if (walker != nullptr) {
        while (walker->_next != nullptr) {
            walker = walker->_next;
        }
    }
    return walker;
}

#endif // NODE_H
