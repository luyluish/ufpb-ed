#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

#define MAX 100 // Maximum array size

class Array {
private:
    int data[MAX];
    int size;

public:
    Array(); // Constructor

    bool isEmpty();
    bool isFull();
    int getSize();
    int getElement(int pos);
    bool modifyElement(int pos, int value);
    bool insertElement(int pos, int value);
    bool removeElement(int pos);
    void printArray();
};

#endif // ARRAY_H