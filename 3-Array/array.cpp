#include "array.h"

#define MAX 100 // Max size for the array

Array::Array() { size = 0; } // 1) Constructor for the array class, by default empty

bool Array::isEmpty() { return size == 0; } // 2) Check if array is empty
bool Array::isFull() { return size == MAX; } // 3) Check if array is full
int Array::getSize() { return size; } // 4) Get current array size

// 5.1) Get an element by its position
int Array::getElement(int pos) {
    if (pos < 1 || pos > size) {
        return false;
    }

    int value = data[pos - 1]; // Subtract by 1 to get vector index
    return value; 
}

// 5.2) Modify an element at a certain position
bool Array::modifyElement(int pos, int value) {
    if (pos < 1 || pos > size) {
        return false;
    }

    data[pos - 1] = value;
    return true;
}

// 6) Insert new element at a certain position
bool Array::insertElement(int pos, int value) {
    if (isFull() || pos < 1 || pos > size + 1) {
        return false;
    }

    // Shift current array to make space for the new element
    for (int i = size; i >= pos; i--) {
        data[i] = data[i - 1];
    }

    data[pos - 1] = value;
    size++; // Increase current size by 1
    return true;
}

// 7) Remove element from a certain position
bool Array::removeElement(int pos) {
    if (pos < 1 || pos > size) {
        return false;
    }

    // Shift current array to remove the leftover space
    for (int i = pos - 1; i < size - 1; i++) {
        data[i] = data[i + 1];
    }

    size--; // Reduce current size by 1
    return true;
}

// Print whole array for debugging purposes
void Array::printArray() {
    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}