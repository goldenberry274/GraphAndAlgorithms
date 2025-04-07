//
// Created by eitan on 4/5/25.
//

#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <stdio.h>


class UnionFind {


protected:
    size_t* parents;
    int* sizes;
    size_t size;

public:
  UnionFind(size_t union_size);
  void union_sets(size_t a, size_t b);
  size_t find(size_t ind);
    ~UnionFind();


};



#endif //UNIONFIND_H
