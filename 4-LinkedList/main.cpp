#include "linkedlist.h"

int main() {
    LinkedList list;
    int value;

    std::cout << "=============================" << std::endl;
    std::cout << "Test 1: Check if the list is empty" << std::endl;
    std::cout << "Is the list empty? " << list.isEmpty() << std::endl;
    std::cout << "=============================" << std::endl;
    
    std::cout << "Test 2: Insert elements into the list" << std::endl;
    list.insertElement(1, 10);
    list.insertElement(2, 20);
    list.insertElement(3, 30);
    list.insertElement(2, 15);
    list.printList();
    std::cout << "=============================" << std::endl;

    std::cout << "Test 3: Get list size" << std::endl;
    std::cout << "List size: " << list.getSize() << std::endl;
    std::cout << "=============================" << std::endl;

    std::cout << "Test 4: Get an element by position" << std::endl;
    value = list.getElement(2);
    std::cout << "Element at position 2: " << value << std::endl;
    std::cout << "=============================" << std::endl;

    std::cout << "Test 5: Modify an element" << std::endl;
    list.modifyElement(3, 25);
    list.printList();
    std::cout << "=============================" << std::endl;

    std::cout << "Test 6: Remove an element" << std::endl;
    list.removeElement(1);
    list.printList();
    std::cout << "=============================" << std::endl;

    std::cout << "Test 7: Check if the list is empty again" << std::endl;
    std::cout << "Is the list empty? " << list.isEmpty() << std::endl;
    std::cout << "=============================" << std::endl;

    system("pause");
    return 0;
}