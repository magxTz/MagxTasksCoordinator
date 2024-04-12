#ifndef VECTOR_H
#define VECTOR_H

#include <string.h>     /* memcpy */

#define min(a,b) (a < b) ? a : b

template <typename T>
class vector {
public:
    vector() : __capacity(0), __count(0), __data(0) {} //empty constructor
    vector(T obj, int count = 1) {

        if (this->__data) { // free data ptr if used
            delete this->__data;
        }

        this->__data = new T[count];
        this->__count = count;
        this->__capacity = count;

        for (int i = 0; i < count; i++) //populate array with given object
            this->__data[i] = obj;

    }

    ~vector() {

        if (this->__data) { // free data ptr if used
            delete [] this->__data;
        }

        this->__count = this->__capacity = 0;
    }

    T const & operator[] (unsigned int idx) const {
        if (idx < this->__count) {
            return this->__data[idx];
        }
        else {
            // throw exception or handle error to be implemented
        }
    }

    T& operator[] (unsigned int idx) {
        if (idx < this->__count) {
            return this->__data[idx];
        }
        else {
            // throw exception or handle error to be implemented
        }
    }

    void resize_to_fit() {
        resize(this->__count);
    }
    T* begin() {
        return __data;
    }

    T* end() {
        return __data + __count;
    }

    T& pop_back(){
        return this->__data[--this->__count];
    }

    void push_back(T obj) {

        if (this->__capacity == this->__count) {
            resize(this->__capacity + 1);
        }

        this->__data[this->__count++] = obj;
    }

    bool isempty() {
        return !this->__data ||
            !this->capacity ||
            !this->size;
    }

    void clear() {
        this->~vector();
    }

    T* data() {
        return this->__data;
    }

    int size() {
        return this->__count;
    }

    int capacity() {
        return this->__capacity;
    }
private:
    void resize(int capacity) {
        if (this->__data == nullptr) {
            this->__data = new T[capacity];

            this->__count = 0;
            this->__capacity = capacity;
        }
        else if (capacity != this->__capacity) { //else do nothing

            T* data = new T[capacity];

            this->__count = min(this->__count, capacity);
            this->__capacity = capacity;

            memcpy(data, this->__data, sizeof(T) * this->__count);

            delete this->__data; //program crashes here, but the pointer is already broken...
            this->__data = data;
        }
    }
protected:

        int __capacity;
        int __count;
        T* __data;



};
#endif//VECTOR_H
