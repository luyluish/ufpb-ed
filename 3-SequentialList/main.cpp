#include "list.h"

int main() {
    List list;
    int value;

    list.printList();
    std::cout << "Is the list empty? " << list.isEmpty() << std::endl;
    std::cout << "=============================" << std::endl;
    
    list.insertElement(1, 10);
    list.insertElement(2, 20);
    list.insertElement(3, 30);
    list.printList();
    std::cout << "Is the list empty? " << list.isEmpty() << std::endl;
    value = list.getElement(2);
    std::cout << "Element at position 2: " << value << std::endl;
    std::cout << "=============================" << std::endl;

    list.modifyElement(2, 25);
    list.printList();

    list.removeElement(1);
    list.printList();

    std::cout << "List size: " << list.getSize() << std::endl;
    std::cout << "=============================" << std::endl;
    system("pause");

    return 0;
}