#include "list.h"

#define MAX 100 // Max size for the list

List::List() { size = 0; } // 1) Constructor for the list class, by default empty

bool List::isEmpty() { return size == 0; } // 2) Check if list is empty
bool List::isFull() { return size == MAX; } // 3) Check if list is full
int List::getSize() { return size; } // 4) Get current list size

// 5.1) Get an element by its position
int List::getElement(int pos) {
    if (pos < 1 || pos > size) {
        return false;
    }

    int value = data[pos - 1]; // Subtract by 1 to get vector index
    return value; 
}

// 5.2) Modify an element at a certain position
bool List::modifyElement(int pos, int value) {
    if (pos < 1 || pos > size) {
        return false;
    }

    data[pos - 1] = value;
    return true;
}

// 6) Insert new element at a certain position
bool List::insertElement(int pos, int value) {
    if (isFull() || pos < 1 || pos > size + 1) {
        return false;
    }

    // Shift current list to make space for the new element
    for (int i = size; i >= pos; i--) {
        data[i] = data[i - 1];
    }

    data[pos - 1] = value;
    size++; // Increase current size by 1
    return true;
}

// 7) Remove element from a certain position
bool List::removeElement(int pos) {
    if (pos < 1 || pos > size) {
        return false;
    }

    // Shift current list to remove the leftover space
    for (int i = pos - 1; i < size - 1; i++) {
        data[i] = data[i + 1];
    }

    size--; // Reduce current size by 1
    return true;
}

// Print whole list for debugging purposes
void List::printList() {
    std::cout << "List: ";
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}