//
// Eitan.Beriy@msmail.ariel.ac.il
//

#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdio.h>

struct Edge {
    size_t src;
    int weight;
    size_t dst;
};


class MinHeap {
protected:

    Edge* heap;
    size_t* positions;  // maps dst node to position in heap
    size_t capacity;
    size_t size;

    void swap(size_t i, size_t j);
    void heapify_up(size_t index);
    void heapify_down(size_t index);

public:
    MinHeap(size_t max_size);
    ~MinHeap();
    void push(Edge e);
    Edge pop();
    bool isEmpty();
};



#endif //MINHEAP_H
