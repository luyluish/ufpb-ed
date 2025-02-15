#include "linkedlist.h"

// 1) Constructor for the LinkedList class, by default empty
LinkedList::LinkedList() : head(nullptr), size(0) {}

// 2) Destructor, making sure to deallocate the memory for each node
LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    std::cout << "LinkedList destroyed." << std::endl;
}

// 3) Check if list is empty
bool LinkedList::isEmpty() {
    return size == 0;
}

// 4) Get list size
int LinkedList::getSize() {
    return size;
}

// 5) Get an element from specific position (starting at 1)
int LinkedList::getElement(int pos) {
    if (pos < 1 || pos > size) {
        return -1;
    }
    Node* current = head;
    // Iterate through whole list, stopping at the position parameter
    for (int i = 1; i < pos; i++) {
        current = current->next;
    }
    return current->data;
}

// 6) Modify element at specific position
bool LinkedList::modifyElement(int pos, int value) {
    if (pos < 1 || pos > size) {
        return false;
    }
    Node* current = head;
    for (int i = 1; i < pos; i++) {
        current = current->next;
    }
    current->data = value;
    std::cout << "Modified element at position " << pos << " to " << value << std::endl;
    return true;
}

// 7) Insert element at specific position
bool LinkedList::insertElement(int pos, int value) {
    if (pos < 1 || pos > size + 1) {
        return false;
    }
    // Create new node for the new element
    Node* newNode = new Node(value);

    // Change head node if inserting at position 1
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 1; i < pos - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
    std::cout << "Inserted element " << value << " at position " << pos << std::endl;
    return true;
}

// 8) Remove element at specific position
bool LinkedList::removeElement(int pos) {
    if (pos < 1 || pos > size) return false;
    Node* temp;

    // Now, change head node to next one if removing from position 1
    if (pos == 1) {
        temp = head;
        head = head->next;
    } else {
        Node* current = head;
        for (int i = 1; i < pos - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }
    std::cout << "Removed element " << temp->data << " from position " << pos << std::endl;
    delete temp;
    size--;
    return true;
}

// Printing the list for debug purposes
void LinkedList::printList() {
    Node* current = head;
    std::cout << "List: ";
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}