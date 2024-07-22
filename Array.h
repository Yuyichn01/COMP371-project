#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array {
private:
    T* array;
    int size;

public:
    Array(int size = 0);
    ~Array();
    
    void initializeArray();
    void printArray() const;
    void deleteArray();
    
    T getElement(int index) const;
    void setElement(int index, T value);

    void resize(int newSize);
};

#endif
