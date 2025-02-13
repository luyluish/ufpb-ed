#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

#define MAX 100 // Maximum list size

class List {
private:
    int data[MAX];
    int size;

public:
    List(); // Constructor

    bool isEmpty();
    bool isFull();
    int getSize();
    int getElement(int pos);
    bool modifyElement(int pos, int value);
    bool insertElement(int pos, int value);
    bool removeElement(int pos);
    void printList();
};

#endif // ARRAY_H