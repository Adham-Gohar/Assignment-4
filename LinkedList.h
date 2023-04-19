#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>

struct Node //struct for each node
{
    int value;
    int count;
    Node* next;
    Node(int val) : value(val), count(1), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList(); // conestructor
    ~LinkedList(); //destructor
    void addNode(int val); //add a node to the linked lists
    bool removeNode(int val); //remove a node from the linked lists
    void printList(); // print the linked list
    static LinkedList fromVector(const std::vector<int>& vec); //makes a linked list from a vector 
    int sumNodes(); // returns the sum of nodes

private:
    Node* head;
};

#endif
