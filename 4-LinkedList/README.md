# Task 4: Linked List Implementation

This project implements a linked list in C++. The linked list is a type of list where each node (element) contains a reference to the next element, while the last one points to a null pointer. It supports basic operations such as insertion, deletion, modification, and retrieval of elements inside the list.

## Features

- Inserting elements at a specific position.
- Removing elements from a specific position.
- Modifying elements at a specific position.
- Retrieving elements by their position.
- Checking if the list is empty or full.
- Getting the current size of the list.

## How to Run

To compile and run the program, use a C++ compiler such as g++. Example:

```sh
g++ main.cpp linkedlist.cpp node.cpp -o linkedlist
./linkedlist
```

## Files

``node.h``: Header file defining a Node class, for each node in the list.

``node.cpp``: Implementation of the Node class methods.

``linkedlist.h``: Header file defining the LinkedList class.

``linkedlist.cpp``: Implementation of the LinkedList class methods.

``main.cpp``: Contains the main function to demonstrate the linked list operations.