//
// Created by eitan on 3/21/25.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>

struct Node {
    size_t node_number;
    int weight;
    Node* next;
    Node(size_t new_node_number, int new_weight = 1, Node* new_next = NULL);
    Node();
    Node(const Node& copy_this);
    ~Node();
    static void deleteNode(Node* nodePtr);

};

class LinkedList {
protected:
    Node* head;
public:

    LinkedList();
    LinkedList(size_t first_vertex = 0);
    LinkedList(const LinkedList& other);
    Node* get_head();
    void print_list();
    void addEdge(size_t new_vertex, int new_weight = 1);
    bool removeEdge(size_t remove_this);
    ~LinkedList();

};



#endif //LINKEDLIST_H
