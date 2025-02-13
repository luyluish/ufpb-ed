#include "array.h"

int main() {
    Array array;
    int value;

    array.printArray();
    std::cout << "Is the array empty? " << array.isEmpty() << std::endl;
    std::cout << "=============================" << std::endl;
    
    array.insertElement(1, 10);
    array.insertElement(2, 20);
    array.insertElement(3, 30);
    array.printArray();
    std::cout << "Is the array empty? " << array.isEmpty() << std::endl;
    value = array.getElement(2);
    std::cout << "Element at position 2: " << value << std::endl;
    std::cout << "=============================" << std::endl;

    array.modifyElement(2, 25);
    array.printArray();

    array.removeElement(1);
    array.printArray();

    std::cout << "Array size: " << array.getSize() << std::endl;
    std::cout << "=============================" << std::endl;
    system("pause");

    return 0;
}