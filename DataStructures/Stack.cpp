//
// Created by eitan on 3/29/25.
//

#include "Stack.h"

Stack::Stack(size_t V){
  if (0 == V)
    throw "Invalid argument";
  capacity = V;
  arr = new size_t[V];
  top = -1;
}

bool Stack::push(size_t value){
  if (top < capacity - 1){
    top++;
    arr[top] = value;
    return true;
  }
  return false;
}

size_t Stack::get_top(){
  if (isEmpty())
    throw "Stack is empty";
  return arr[top];
}
size_t Stack::pop(){
  if (top < 0)
    throw "Stack is empty";
  size_t data;
  data = arr[top];
  top = top--;
  return data;

}

bool Stack::isEmpty(){
  return top == -1;
}

Stack::~Stack(){
  delete[] arr;
}
