//
// Eitan.Beriy@msmail.ariel.ac.il
//
#include "Graph.h"

namespace graph {

    Graph::Graph(size_t new_vatrices_num) : vatrices_num ( new_vatrices_num), edge_lists (nullptr)

    {
        if (0 == vatrices_num)
            return;

        edge_lists = new LinkedList * [vatrices_num];

        for (int i = 0; i < vatrices_num; i++) {
            edge_lists[i] = new LinkedList(i);
        }

    }

    bool Graph::addEdge(size_t src, size_t dst, int weight) {
        if (src >= vatrices_num || dst >= vatrices_num)
            return false;

        edge_lists[src]->addEdge(dst, weight);
        edge_lists[dst]->addEdge(src, weight);
        return true;
    }

    void Graph::removeEdge(size_t src, size_t dst) {
        if (src >= vatrices_num || dst >= vatrices_num)
            throw "Invalid argument";
        if (src == dst)
            throw "Invalid argument";

        if (!edge_lists[src]->removeEdge(dst) || !edge_lists[dst]->removeEdge(src)) {
            throw "Nonexistent edge";
        }

    }


    void Graph::print_graph() {

        for (int i = 0; i < vatrices_num; i++) {
            printf("Edges of vertex %d: ", i);
            edge_lists[i]->print_list();
        }
    }

    size_t Graph::get_size() {
        return vatrices_num;
    }

    size_t Graph::get_edge_num() {
        size_t edges = 0;

        LinkedList** tmpList = edge_lists;

        for (int i = 0; i < vatrices_num; i++) {
            Node* tmp = tmpList[i]->get_head()->next;
            while (nullptr != tmp) {
                edges++;
                tmp = tmp->next;
            }
        }
        return edges / 2;
    }

    LinkedList **Graph::get_vetrex_list() {
        LinkedList** copy_of_list = new LinkedList *[vatrices_num];
        for (int i = 0; i < vatrices_num; i++) {
            copy_of_list[i] = new LinkedList(*edge_lists[i]);
        }
        return copy_of_list;
    }

    void Graph::delete_vertex_list(LinkedList** delete_this, size_t size) {

        for (size_t i = 0; i < size; i++) {
            delete delete_this[i];
            delete_this[i] = nullptr;
        }

        delete[] delete_this;

    }

    Graph::~Graph() {

        for (size_t i = 0; i < vatrices_num; i++) {
            delete edge_lists[i];
            edge_lists[i] = nullptr;
        }

        delete[] edge_lists;
        edge_lists = nullptr;
    }
}
