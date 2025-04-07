//
// Eitan.Beriy@msmail.ariel.ac.il
//

#ifndef STACK_H
#define STACK_H

#include <stdio.h>

class Stack {
protected:
    size_t* arr;
    int top, capacity;
public:
  Stack(size_t V);
  bool push(size_t value);
  size_t pop();
  size_t get_top();
  size_t size();
  bool isEmpty();
  ~Stack();
};





#endif //STACK_H
