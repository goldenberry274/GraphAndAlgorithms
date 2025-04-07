//
// Eitan.Beriy@msmail.ariel.ac.il
//

#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include "DataStructures/LinkedList.h"

namespace graph{
    //Class Graph is undirected, meaning any edge from vertex a to b is also an edge from vertex b to a
    class Graph {

    protected:
        const size_t vatrices_num;
        LinkedList** edge_lists;

    public:

        //Throws exception if argument is invalid (0)
        Graph(size_t new_vatrices_num);
        //Adds an edge from node src to node dst with the weight "weight"
        bool addEdge(size_t src, size_t dst, int weight = 1);
        //Removes the edge no.src to no.dst and vice versa
        void removeEdge(size_t src, size_t dst);
        //Prints the graph
        void print_graph();
        //Returns the amount of vatrices in the graph
        size_t get_size();
        //Returns the amount of edges in the graph
        size_t get_edge_num();
        //Freeing the memory for this object is the reponsibility of the caller
        LinkedList** get_vetrex_list();
        //Frees LinkedList** that's from get_vertex_list()
        static void delete_vertex_list(LinkedList** delete_this, size_t size);
        ~Graph();


    };

}



#endif //GRAPH_H
