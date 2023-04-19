#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void LinkedList::addNode(int val) {
    //if the list is emty, make a new node as the head
    if (head == nullptr) {
        head = new Node(val);
    }
    //else, find the last node and add a new one after it
    else 
    {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new Node(val);
    }
}

bool LinkedList::removeNode(int val) {
    //if the list is empty, retur false
    if (head == nullptr) 
    {
        return false;
    }
    // if we are removing the head, the next node after is going to be the new head
    if (head->value == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    Node* curr = head;
    while (curr->next != nullptr) 
    {
        if (curr->next->value == val) 
        {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            return true;
        }
        curr = curr->next;
    }
    //if it did not find the nde, return false
    return false;
}

void LinkedList::printList() {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->value << "(" << curr->count << ")" << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

LinkedList LinkedList::fromVector(const std::vector<int>& vec) {
    LinkedList list;
    for (int val : vec) {
        Node* curr = list.head;
        //if the value is already in the list, increase its count
        while (curr != nullptr) {
            if (curr->value == val) {
                curr->count++;
                break;
            }
            curr = curr->next;
        }
        // if the value is not in the list, add it as a new node
        if (curr == nullptr) {
            list.addNode(val);
        }
    }
    return list;
}

int LinkedList::sumNodes() {
    int sum = 0;
    Node* curr = head;
    while (curr != nullptr) {
        sum += curr->value * curr->count;
        curr = curr->next;
    }
    return sum;
}
