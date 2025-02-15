#ifndef NODE_H
#define NODE_H

class Node {
public:
    int data;
    Node* next;
    Node(int value); // Construtor, deve ser inicializado com um valor
};

#endif // NODE_H