#define _CRTDBG_MAP_ALLOC
#pragma once
#include "linked_list.h"

template<typename T>
class Queue {
public:
    Queue();

    ~Queue() {};
    Queue(const Queue& og);
    Queue& operator =(const Queue<T>& og);

    class Iterator {
        friend class Queue;
    public:
        //Error checking done in List's iterator
        Iterator(typename List<T>::Iterator p = typename List<T>::Iterator()) :_ptr(p) {}

        Iterator next()                     //return an iterator to the
        {
            //next location in the list
            return Iterator(_ptr.next());
        }

        /*You should not be able to change items inside the queue*/

        const T* operator->()const {                    //dereference operator
            return _ptr.operator->();
        }

        const T& operator *()const {        //dereference operator
            return *_ptr;
        }

        friend Iterator operator ++(Iterator& it, int unused) {
            Iterator hold;
            hold = it;
            it = it.next();
            return hold;
        }

        Iterator& operator ++() {
            return _ptr++;
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
        typename List<T>::Iterator _ptr;
    };

    typename Queue<T>::Iterator push(const T& item);
    T pop();

    friend ostream& operator <<(ostream& outs, const Queue<T>& s) {
        outs << s._queue;
        return outs;
    }
    typename Queue<T>::Iterator end() const { return Iterator(nullptr); }
    typename Queue<T>::Iterator begin() const { return Iterator(_queue.begin()); }
    //return the tail of the list

    int size() { return _size; }

    T& operator[](int index);

private:
    int _size;
    List<T> _queue;
    typename List<T>::Iterator _rear;
    void copy_queue(const Queue& og);
    void set_rear();
};

template<typename T>
Queue<T>::Queue() {
    _size = 0;
    _rear = _queue.begin();
}

template<typename T>
Queue<T>::Queue(const Queue& og) {
    copy_queue(og);
}

template<typename T>
Queue<T>& Queue<T>::operator =(const Queue& og) {
    if (&og != this) {
        copy_queue(og);
    }
    return *this;
}

template<typename T>
void Queue<T>::copy_queue(const Queue& og) {
     _queue = og._queue;
     _size = og._size;
     set_rear();
}

template <typename T>
void Queue<T>::set_rear() {
    //Shows ++ and .next() work
    if (_queue.begin() != _queue.end()) {
        typename List<T>::Iterator walker = _queue.begin();
        while (walker.next() != _queue.end()) {
            walker++;
        }
        _rear = walker;
    }
    else {
        _rear = _queue.end();
    }
}

template<typename T>
typename Queue<T>::Iterator Queue<T>::push(const T& item) {

    typename List<T>::Iterator it = _queue.insertAfter(item, _rear);
    _rear = it;

    _size++;
    return Iterator(it);
}

template<typename T>
T Queue<T>::pop() {
    if (_size > 0) {
        T hold = _queue.remove_head();
        _size--;
        return hold;
    }
    else
        assert(0 && "Queue is empty");
}

template<typename T>
T& Queue<T>::operator[](int index) {
    return(_queue[index]);
}