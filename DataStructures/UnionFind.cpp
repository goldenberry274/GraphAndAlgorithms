//
// Created by eitan on 4/5/25.
//

#include "UnionFind.h"

UnionFind::UnionFind(size_t union_size){
  if (union_size == 0)
    throw "Invalid argument";

  parents = new size_t[union_size];
  sizes = new int[union_size];
  size = union_size;
  for (size_t i = 0; i < union_size; i++){
    parents[i] = i;
    sizes[i] = 1;
  }
}

size_t UnionFind::find (size_t x){
  if (x >= size){
    throw "Invalid argument";
  }
  if (parents[x] != x)
    parents[x] = find(parents[x]);
  return parents[x];
}

void UnionFind::union_sets(size_t a, size_t b){
  if (a >= size || b >= size)
    throw "Invalid argument";

  a = find(a);
  b = find(b);
  if (a != b)
    parents[b] = a;
}

UnionFind::~UnionFind() {
  delete[] parents;
  delete[] sizes;
}


