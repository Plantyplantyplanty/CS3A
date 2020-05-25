#pragma once
//Visual studio doesn't like ifndef for templated classes and libraries
//NO FOR LOOPS
#include "AddEntry.h"
#include "1DLibrary.h"

 /**************************************************************************************
CLASS DEFINITION
***************************************************************************************
*/

template <class T>
class Vector {

public:
   
    Vector(unsigned int cap = 100);
   

    // big three:
    Vector(Vector<T> const &original);
    Vector& operator =(const Vector<T>& original);
    void copy_vector(Vector<T> const& original);
    ~Vector();
        //member access functions:

    //RESERVE AND RESIZE
    const T operator [](const unsigned int index) const;
    T& operator [](const unsigned int index);
    T& at(int index);             //return reference to item at position index
    const T at(int index) const;  //return a const item at position index
    T& front() const;             //return item at position 0.
    T& back() const;              //return item at the last position

    //Push and Pop functions:
    Vector& operator +=(const T& item); //push_back
    void push_back(const T& item);      //append to the end
    T pop_back();                       //remove last item and return it


    //Insert and Erase:
    void insert(int insert_here, const T& insert_this); //insert at pos
    void erase(int erase_index);        //erase item at position
    int index_of(const T& item);        //search for item. retur index.

    //size and capacity:
    void set_size(int size);            //enlarge the vector to this size
    void set_capacity(int capacity);    //allocate this space
    int size() const { return _size; } //return _size    
    int capacity() const { return _capacity; } //return _capacity

    bool empty() const;                 //return true if vector is empty

    //OUTPUT:
    template <class U>
    friend ostream& operator <<(ostream& outs, const Vector<U>& _a);

    //Equality
    //_capacity does not have to be equal for the vectors to be equal, according to the book   
    template <class U>
    friend bool operator ==(const Vector<U>& V1, const Vector<U>& V2);

    //Error Handling
    int is_error() { return _error; }
    string error_description();

    const int NO_ERROR = 0;

private:
    int _size; //how full the vector is
    int _capacity; // the capacity of the vector
    unsigned int _min_cap; //The minimum size the vector can be re-sized to
    int _error; //The current error state

    T* backbone; //Where the contents of the Vector are held

    //Error handling
    bool clear(); //returns if "clear" has been successful or not
    int error(); //returns if the object should be in an error state;
};

/**************************************************************************************
FUNCTIONS
***************************************************************************************
*/


/*Default Constructor: Creates a new vector with capacity "cap". If no "cap" is provided, 
                       "cap" is set to 100.
---------------------
Preconditions: cap >= 0
Postconditions: a new Vector object has been created
*/
template<typename T>
Vector<T>::Vector(unsigned int cap) {
    //Sets the variables of the class
    _capacity = cap;
    _min_cap = 0;
    _error = NO_ERROR;
    _size = 0;

    //Allocates a _capacity size dynamic array to "backbone"
    backbone = allocate<T>(_capacity);

    error();
}

/*Copy Constructor: Creates a new vector which is a copy of the Vector object "original".
---------------------
Preconditions: "original" is a valid vector object of the same type.
Postconditions: a new Vector object has been created which has all of the same values as 
                "original".
*/
template<typename T>
Vector<T>::Vector(Vector<T> const& original){
    copy_vector(original);
}

template<typename T>
void Vector<T>::copy_vector(Vector<T> const& original) {
    //Sets the variables of the classes to be equal
    _size = original._size;
    _capacity = original._capacity;
    _min_cap = original._min_cap;
    _error = original._error;

    //Allocates a _capacity size dynamic array to "backbone"
    backbone = allocate<T>(_capacity);
    //Copies the "backbone" of original into the new Vector's "backbone"
    copy_list(backbone, (original.backbone), _size);
}

/*Destructor: Deletes the dynamic part of the class
---------------------
Preconditions: none
Postconditions: "backbone" has been deleted
*/
template<typename T>
Vector<T>::~Vector<T>() {
    delete [] backbone;
}

/*Sets the first object equal to the second object and destroys the first object's values*/
template<typename T>
Vector<T>& Vector<T>::operator =(const Vector<T>& original) {
    if (this == &original) {
        //do nothing
    }
    else {
        delete[] backbone;

        copy_vector(original);
    }
    return *this;
}

/*Allows us to use [] to index the vector
----------------------------------------
Preconditions: index is within bounds of "backbone" and has been initialized;
Postconditions: everything is unchanged
*/
template<typename T>
const T Vector<T>::operator [](const unsigned int index) const{
    assert(index < _size && index >= 0);

    //get the address at "index"
    const T* index_address = backbone + index;
    return *index_address;
}

/*Allows us to use [] to index the vector
----------------------------------------
Preconditions: index is within bounds of "backbone" and has been initialized;
Postconditions: everything is unchanged
*/
template<typename T>
T& Vector<T>::operator [](const unsigned int index) {
    assert(index < _size && index >= 0);

    //get the address at "index"
    T* index_address = backbone + index;
    return index_address;
}

/*Allows us to .at() to index the vector
----------------------------------------
Preconditions: index is within bounds of "backbone" and has been initialized;
Postconditions: everything is unchanged
*/
template<typename T>
const T Vector<T>::at(int index) const{
    assert(index < _size && index >= 0);

    //get the address at "index"
    const T* index_address = backbone + index;
    return *index_address;
}


/*Allows us to .at() to index the vector
----------------------------------------
Preconditions: index is within bounds of "backbone" and has been initialized;
Postconditions: everything is unchanged
*/
template<typename T>
T& Vector<T>::at(int index) {
    assert(index < _size && index >= 0);

    //get the address at "index"
    T* index_address = backbone + index;
    return *index_address;

}

/*Inserts an object, "insert_this", at "insert_here" in the Vector
---------------------
Preconditions: "insert_here" is a valid index, and "insert_this" is a valid object.
Postconditions: "insert_this has been inserted at "insert_here".
*/
template <typename T>
void Vector<T>::insert(int insert_here, const T& insert_this) {
    assert(insert_here >= 0 && insert_here <= _size);
   
    //Gets the address at "insert_here"
    T* address = backbone + insert_here;
    //Shift all elements to the right after "insert_here". Re-sizes the array if necessary.
    backbone = shift_right(backbone, address, _size, _capacity);

    //Adds the element at the "insert_here"
    address = backbone + insert_here; //need to re-define in case of re-allocation
    *address = insert_this;
   
}

/*Erases the item at the "erase_index"
---------------------
Preconditions: index is within bounds of "backbone"
Postconditions: "backbone" no longer contains the index and _size is one smaller
*/
template <typename T>
void Vector<T>::erase(int erase_index){
    assert(erase_index >= 0 && erase_index <= _size && _size > 0);

    //The address of erase_index
    T* address = backbone + erase_index;
    //Shift the next values down at that point
    backbone = shift_left(backbone, address, _size);

    if (_size < (_capacity / LOWER_LIMIT) && ((_capacity / MULTIPLE) >= int(_min_cap))) {
        backbone = size_down(backbone, _size, _capacity);
    }
}

/*Finds and returns the index of the item; returns -1 if not found
------------------------------------------------------------------
Preconditions: "backbone" has been initialized
Postconditions: Everything is the same
*/
template <typename T>
int Vector<T>::index_of(const T& item){
    //Searches the array for the item
    assert(_size > 0);
    T* address = search_entry(backbone, item, _size);

    //if the address exists:
    if (address != nullptr) {
        return (address - backbone);
    }
    else {
        //but if it doesn't:
        return -1;
    }
}

/*Enlarges "backbone"'s size to the given size
-----------------------------------------
Preconditions: size is greater than or equal to _size 
Postconditions: The size(and the capacity, potentially) have been increased. Up to that size have
                been initialized to to T();
*/
template<typename T>
void Vector<T>::set_size(int size) {
    assert(size >= _size);

    //Resizes the array to hold all of the items
    if (size > _capacity) {
        backbone = reallocate(backbone, _capacity, _size, size* 2);
        _capacity = size * 2;
    }

    //Where it needs to start filling
    T* to_fill = backbone + _size ;
    //Fill up to the given size
    intialize1D<T>(to_fill, size);
    _size = size;
}

/*Makes the capacity larger
---------------------
Preconditions: new capacity is larger than the old capacity(capacity > _capacity)
Postconditions: "backbone" is now in a "capacity" size array;
*/
template<typename T>
void Vector<T>::set_capacity(int capacity) {
    assert(capacity >= _capacity);

    //Resize the array
    backbone = reallocate(backbone, _capacity, _size, capacity);
}

/*Returns the value at backbone[0]
----------------------------------
Preconditions: there is a value stored at *backbone
Postconditions: everything is unchanged
*/
template<typename T>
T& Vector<T>::front() const {
   assert(!empty());

   T f = *backbone;
   return f;
}

/*Returns the value at the end of the stored values in backbone
----------------------------------
Preconditions: there is a value stored in backbone
Postconditions: everything is unchanged
*/
template<typename T>
T& Vector<T>::back() const {
    assert(!empty());
    T * back_address = backbone + _size - 1;
    return (*back_address);
}

/*Adds an entry to the back of "backbone"
----------------------------------
Preconditions: "item" can be a valid member of backbone
Postconditions: backbone is size+1 larger and might have been reallocated to capacity * 2
*/
template<typename T>
void Vector<T>::push_back(const T& item) {
    if (!_error) {
        backbone = add_entry(backbone, item, _size, _capacity);
    }
}

/*Adds an entry to the back of "backbone"(same as "push_back"
----------------------------------
Preconditions: "item" can be a valid member of backbone
Postconditions: backbone is size+1 larger and might have been reallocated to capacity * 2
*/
template<typename T>
Vector<T>& Vector<T>::operator +=(const T& item) {
    push_back(item);
    return *this;
}

/*Returns the entry at the back of "backbone" and removes in from "backbone"
----------------------------------
Preconditions: "backbone" contains a value
Postconditions: backbone is size-1 smaller and might have been reallocated to capacity/4
*/
template<typename T>
T Vector<T>::pop_back() {
    T* item_address = nullptr;
    T item;
    assert(!empty());
        item_address = _size - 1 + backbone;
        item = *item_address;
        item_address = nullptr;
        _size--;

        //if size is less than capacity/4 and capacity/2 is less than the minimum capacity
        if (_size < (_capacity / LOWER_LIMIT) && ((_capacity / MULTIPLE) >= int(_min_cap))) {
            backbone = size_down(backbone, _size, _capacity);
        }
 
    return item;
}

/*Returns if "backbone" is empty or not
---------------------------------------
Pre & Postconditions: None
*/
template<typename T>
bool Vector<T>::empty() const {
    if (_size == 0) {
        return true;
    }
    else
        return false;
}

/*Returns an ostream object of the vector
-----------------------------------------
Preconditions: both objects are valid
Postconditions: "outs" is returned with the vector
*/
template <class U>
ostream& operator <<(ostream& outs, const Vector<U>& _a) {
    for (int i = 0; i < _a._size; i++) {
        outs << _a[i] << " ";
    }
    outs << endl;
    return outs;
}

template <class U>
bool operator ==(const Vector<U>& V1, const Vector<U>& V2) {
    bool equal = false;

    if (V1._size == V1._size) {
        equal = equal_list(V1.backbone, V2.backbone, V1._size);
    }

    return equal;
}


/*Returns if the object is in error. Not used.*/
template<typename T>
int Vector<T>::error() {
    bool err = NO_ERROR;

    _error = err;
    return _error;
}

/*Returns a description of the object's error state. Not used.*/
template<typename T>
string Vector<T>::error_description() {
    string error = "";
    if (_error = NO_ERROR) {
        error = "No error";
    }
    return error;
}

//Clears the object's error state. Not used.
template<typename T>
bool Vector<T>::clear() {
    _error = NO_ERROR;
    return true;
}