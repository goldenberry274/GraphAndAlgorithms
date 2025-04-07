//
// Eitan.Beriy@msmail.ariel.ac.il
//

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>


class Queue {
protected:

  size_t* arr; //Array for numbers in queue.
  size_t add_index; //Index for which a new element will be added
  size_t capacity; //Capacity of queue, size of 'arr'
  size_t front; //Index for dequeueing
  size_t size; //How many actual numbers are the queue

public:
  //Throws exception if parameter is invalid
  Queue(size_t V);
  ~Queue();
  size_t get_front();
  size_t*& get_arr();
  bool enqueue(size_t value);
  size_t dequeue();
  bool isEmpty();
};



#endif //QUEUE_H
