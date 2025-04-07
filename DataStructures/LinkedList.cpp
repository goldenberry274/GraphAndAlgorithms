//
// Eitan.Beriy@msmail.ariel.ac.il
//

#include "LinkedList.h"
#include <stdio.h>




Node::Node(size_t new_node_number, int new_weight, Node* new_next) {
  node_number = new_node_number;
  weight = new_weight;
  next = new_next;
}

Node::Node(const Node& copy_this) : node_number(copy_this.node_number), weight(copy_this.weight),
                                    next(nullptr) {
  if (copy_this.next != nullptr) {
    next = new Node(*copy_this.next);
  }
}

Node::~Node() {
  delete next;
}

void Node::deleteNode(Node *nodePtr) {
  if (nullptr != nodePtr) {
    delete nodePtr;
  }
}

LinkedList::LinkedList(){
  head = nullptr;
}

LinkedList::LinkedList(size_t first_vertex) {
  int weight_to_self = 0;
  head = new Node(first_vertex, weight_to_self);
}

LinkedList::LinkedList(const LinkedList& other) {
  if (other.head == nullptr) {
    head = nullptr;
    return;
  }

  head = new Node(*other.head);
  Node* current = head;
  Node* other_current = other.head->next;

  while (other_current) {
    Node* new_node = new Node(*other_current);
    current->next = new_node;
    current = new_node;
    other_current = other_current->next;
  }
}


Node *LinkedList::get_head() {
  /*Node* copy_of_head = new Node(*head);

  return copy_of_head;*/
  return head;
}



void LinkedList::addEdge(size_t new_vertex, int new_weight) {
  if (nullptr == head){
    head = new Node(new_vertex, 0);
    return;
  }

  Node* added_node = new Node(new_vertex, new_weight);
  Node* tmpPointer = head;

  while (nullptr != tmpPointer->next){
    tmpPointer = tmpPointer->next;
  }

  tmpPointer->next = added_node;
}


bool LinkedList::removeEdge(size_t remove_this){
  Node* current = head;
  Node* prev = nullptr;

  while (current) {
    if (current->node_number == remove_this) {
      if (prev) {
        prev->next = current->next;
      } else {
        head = current->next;
      }
      delete current;
      printf("Removed vertex %lu\n", remove_this);
      return true;
    }
    prev = current;
    current = current->next;
  }
  return false;

}

void LinkedList::print_list() {
  Node* temp = head;
  temp = temp->next;
  while (temp) {
    printf("(Vertex: %lu, Weight of Edge: %d) -> ", temp->node_number, temp->weight);
    temp = temp->next;
  }
  printf("NULL\n");
}

LinkedList::~LinkedList() {
  Node* current = head;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
}
