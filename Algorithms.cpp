//
// Created by eitan on 30.03.25.
//
#include "Algorithms.h"
#include "DataStructures/Stack.h"
#include "DataStructures/LinkedList.h"
#include "DataStructures/Queue.h"
#include "DataStructures/MinHeap.h"
#include "DataStructures/UnionFind.h"

namespace graph {
    Graph Algorithms::bfs(Graph g, size_t src) {
        if (src >= g.get_size())
            throw "Invalid argument";

        Graph bfs_tree(g.get_size());
        size_t size = g.get_size();
        bool visited[size] = {false};

        Queue q(g.get_size());
        LinkedList** vetrex_list = g.get_vetrex_list();

        visited[src] = true;
        q.enqueue(src);

        while (!q.isEmpty()) {
            size_t bfs_tree_add = q.get_front();
            size_t current = q.dequeue();

            Node* neighbor = vetrex_list[current]->get_head();

            if (neighbor)
                neighbor = neighbor->next;

            while (neighbor) {
                size_t temp = neighbor->node_number;
                if (!visited[temp]) {
                    visited[temp] = true;
                    q.enqueue(temp);
                    bfs_tree.addEdge(bfs_tree_add, temp);
                }
                neighbor = neighbor->next;
            }
        }

        Graph::delete_vertex_list(vetrex_list, g.get_size());
        return bfs_tree;
    }


    Graph Algorithms::dfs(Graph g, size_t src) {
        if (src >= g.get_size())
            throw "Invalid argument";

        Graph dfs_tree(g.get_size());
        size_t size = g.get_size();
        bool visited[size] = {false};

        Stack s(g.get_size());
        LinkedList** vetrex_list = g.get_vetrex_list();

        visited[src] = true;
        s.push(src);

        while (!s.isEmpty()) {
            size_t dfs_tree_add = s.get_top();
            size_t current = s.pop();

            Node* neighbor = vetrex_list[current]->get_head();

            if (neighbor)
                neighbor = neighbor->next;

            while (neighbor) {
                size_t temp = neighbor->node_number;
                if (!visited[temp]) {
                    visited[temp] = true;
                    s.push(temp);
                    dfs_tree.addEdge(dfs_tree_add, temp);
                }
                neighbor = neighbor->next;
            }
        }

        Graph::delete_vertex_list(vetrex_list, g.get_size());
        return dfs_tree;
    }




    Graph Algorithms::dijsktra(Graph g, size_t src) {
        if (src >= g.get_size())
            throw "Invalid argument";

        int* distances = new int[g.get_size()];
        bool* verified = new bool[g.get_size()];
        const size_t INFINITY = 1e9;

        for (size_t i = 0; i < g.get_size(); i++) {
            distances[i] = INFINITY;
            verified[i] = false;
        }

        distances[src] = 0;

        MinHeap heap(g.get_edge_num());
        heap.push({src, 0, src});
        Graph mwt(g.get_size());
        LinkedList** adj_list = g.get_vetrex_list();
        while (!heap.isEmpty()) {
            Edge current = heap.pop();
            size_t curr_edge_dst = current.dst;

            if (verified[curr_edge_dst])
                continue;
            verified[curr_edge_dst] = true;

            adj_list = g.get_vetrex_list();
            Node* neighbor = adj_list[curr_edge_dst]->get_head();

            while (neighbor != nullptr) {
                size_t v = neighbor->node_number;
                int weight = neighbor->weight;
                if (curr_edge_dst == v) {
                    neighbor = neighbor -> next;
                    continue;
                }
                if (weight < 0)
                    throw "Invalid graph given";

                if (!verified[v] && distances[curr_edge_dst] + weight < distances[v]) {
                    distances[v] = distances[curr_edge_dst] + weight;
                    heap.push({curr_edge_dst, weight, v});
                    // Add edge to minimum weight tree
                    mwt.addEdge(curr_edge_dst, v, weight);
                }

                neighbor = neighbor->next;
            }

        }


        delete[] distances;
        delete[] verified;
        return mwt;
    }



    Graph Algorithms::prim(Graph g){

        LinkedList** adjecency_list = g.get_vetrex_list();

        for (size_t i = 0; i < g.get_size(); i++){
            Node* nd = adjecency_list[i]->get_head()->next;
            if (nullptr == nd)
                throw "Invalid argument";
        }

        Graph min_span_tree(g.get_size());
        bool vetrices_in_tree[g.get_size()];

        for (size_t i = 0; i < g.get_size(); i++){
            vetrices_in_tree[i] = false;
        }

        MinHeap pq(g.get_edge_num() * 2);

        //First vertex in the graph, and the only one to be guaranteed to exist
        vetrices_in_tree[0] = true;

        Node* first_node = adjecency_list[0]->get_head()->next;

        while (nullptr != first_node){
            Edge* added = new Edge();
            added->src = 0;
            added->weight = first_node->weight;
            added->dst = first_node->node_number;
            pq.push(*added);
            first_node = first_node->next;
        }

        while (!pq.isEmpty()){
            Edge curr_edge = pq.pop();

            if (vetrices_in_tree[curr_edge.dst])
                continue;

            vetrices_in_tree[curr_edge.dst] = true;
            min_span_tree.addEdge(curr_edge.src, curr_edge.dst, curr_edge.weight);

            Node* curr = adjecency_list[curr_edge.dst]->get_head()->next;
            while (nullptr != curr){
                if (!vetrices_in_tree[curr->node_number]){
                    Edge neighbor_edge;
                    neighbor_edge.src = curr_edge.src;
                    neighbor_edge.weight = curr_edge.weight;
                    neighbor_edge.dst = curr_edge.dst;
                    pq.push(neighbor_edge);
                }
                curr = curr->next;
            }
        }

        return min_span_tree;

    }



    Graph Algorithms::kruskal(Graph g){
        Graph min_span_tree(g.get_size());
        LinkedList** adjecency_list = g.get_vetrex_list();

        //MinHeap is used to sort out the edges by the smallest automatically
        MinHeap min_heap(g.get_edge_num());
        //Insert all the edges into the heap
        for (size_t  i = 0; i < g.get_size(); i++) {
            Node* tmp = adjecency_list[i]->get_head()->next;
            while (nullptr != tmp) {
                Edge new_edge;
                new_edge.src = i;
                new_edge.weight = tmp->weight;
                new_edge.dst = tmp->node_number;
                min_heap.push(new_edge);
                tmp = tmp->next;
            }
        }
        //UnionFind is used to determine if there is a cycle in an efficient way
        UnionFind edge_union(g.get_edge_num());
        //Take out all the edges one by one from the heap and check if they form a cycle.

        while (!min_heap.isEmpty()) {
            Edge curr = min_heap.pop();

            if (edge_union.find(curr.src) != edge_union.find(curr.dst)) {
                min_span_tree.addEdge(curr.src, curr.dst, curr.weight);
                edge_union.union_sets(curr.src, curr.dst);
            }
        }

        return min_span_tree;
    }
}