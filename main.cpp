#include <iostream>
#include "Graph.h"
#include "DataStructures/Queue.h"
#include "DataStructures/LinkedList.h"
#include "Algorithms.h"
using namespace graph;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {


    //Krusktal MNT
    Graph g(3);
    g.addEdge(0,1,-1);
    g.addEdge(1,2,3);
    g.addEdge(2,0);
    Graph k_mst = Algorithms::kruskal(g);
    printf("Kruskal mst \n");
    k_mst.print_graph();

    try {
        Graph g(3);
        g.addEdge(0,1,-1);
        g.addEdge(1,2,3);
        g.addEdge(2,0);

        Graph g_mst = Algorithms::prim(g);
        printf("Prim mst \n");
        g_mst.print_graph();


    } catch (const char* exception) {
        printf("Exception %s \n", exception);
    }
    //Queue main test
    try {
        printf("Creating queue \n");
        Queue q(3);
        //printf("Trying to peek at queue \n");
        //q.peek();
        printf("Enqueuing int 3 \n");
        q.enqueue(3);
        q.dequeue();
        q.dequeue();
    } catch (const char* exception) {
        printf("Exception %s \n", exception);
    }


    try {
        Graph g(5);
        printf("Basic graph before modification: \n");
        g.print_graph();

        g.addEdge(0,1,4);
        printf("Graph modified, added edges 0,1 and 1,0 (The same edge) with weight 4: \n");

        g.print_graph();

        g.removeEdge(0,1);
        printf("Removed edges 0,1 and 1,0 (The same edge)\n");
        g.print_graph();
        printf("This command is supposed to cause an exception due to a nonexistent edge \n");
        g.removeEdge(0,1);

    } catch (const char* exception) {
        printf("Excpetion: %s \n", exception);
    }



    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.