//
// Created by eitan on 30.03.25.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"


namespace graph{
    class Algorithms {
    private:
        Algorithms () {}
     // void insert_and_sort(size_t*& arr, size_t& size);
    public:
        static Graph bfs(Graph g, size_t src);
        static Graph dfs(Graph g, size_t src);
        static Graph dijsktra(Graph g, size_t src);
        static Graph prim(Graph g);
        static Graph kruskal(Graph g);
    };

}




#endif //ALGORITHMS_H
