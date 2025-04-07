//
// Created by eitan on 3/29/25.
//
#include <stdio.h>

#include "Queue.h"

Queue::Queue(size_t V){
  if (0 == V)
    throw "Invalid argument";
  arr = new size_t[V];
  if (nullptr == arr)
    throw "Requested size is too much";
  capacity = V;
  front = 0;
  add_index = -1;
  size = 0;
}

size_t Queue::get_front(){
  return front;
}

size_t*& Queue::get_arr() {
  return arr;
}

bool Queue::enqueue(size_t value){
  if (size >= capacity)
    return false;

  add_index = (add_index + 1) % capacity;
  arr[add_index] = value;
  size++;
  return true;

}

size_t Queue::dequeue(){
  if (size > 0) {
    int val = arr[front];
    front = (front + 1) % capacity;
    size--;
    return val;
  }
  throw "Queue is empty";
}

bool Queue::isEmpty(){
  return size == 0;
}

Queue::~Queue(){
  delete[] arr;
}