//
// Created by eitan on 4/5/25.
//

#include "MinHeap.h"




void MinHeap::swap(size_t i, size_t j) {
        Edge temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;

        // Update positions
        positions[heap[i].dst] = i;
        positions[heap[j].dst] = j;
}

void MinHeap::heapify_up(size_t index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index].weight >= heap[parent].weight)
                break;
            swap(index, parent);
            index = parent;
        }
    }

void MinHeap::heapify_down(size_t index) {
        while (true) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left].weight < heap[smallest].weight)
                smallest = left;
            if (right < size && heap[right].weight < heap[smallest].weight)
                smallest = right;

            if (smallest == index) break;

            swap(index, smallest);
            index = smallest;
        }
    }


MinHeap::MinHeap(size_t max_size) {
        if (max_size == 0)
            throw "Invalid heap size";

        heap = new Edge[max_size];
        positions = new size_t[max_size];
        for (size_t i = 0; i < max_size; ++i)
            positions[i] = -1;

        size = 0;
        capacity = max_size;
}

MinHeap::~MinHeap() {
        delete[] heap;
        delete[] positions;
}

void MinHeap::push(Edge e) {
        size_t dst = e.dst;

        if (positions[dst] != -1) {
            // Already in heap, decrease-key if new weight is smaller
            int idx = positions[dst];
            if (e.weight < heap[idx].weight) {
                heap[idx].weight = e.weight;
                heap[idx].src = e.src;  // update source as well
                heapify_up(idx);
            }
        } else {
            if (size >= capacity)
                throw "Heap overflow";

            heap[size] = e;
            positions[dst] = size;
            heapify_up(size);
            size++;
        }
}

Edge MinHeap::pop() {
        if (size == 0)
            throw "Heap underflow";

        Edge min_edge = heap[0];
        positions[min_edge.dst] = -1;

        heap[0] = heap[--size];
        if (size > 0) {
            positions[heap[0].dst] = 0;
            heapify_down(0);
        }

        return min_edge;
}

bool MinHeap::isEmpty()  {
        return size == 0;
}
