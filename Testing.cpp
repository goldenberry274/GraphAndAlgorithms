
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.h"
#include "Algorithms.h"
#include "DataStructures/Queue.h"
#include "DataStructures/Stack.h"

using namespace graph;


TEST_CASE("Testing queue"){
  Queue q(3);
  CHECK(q.isEmpty() == true);
  q.enqueue(1);
  CHECK(q.get_front() == 0);
  CHECK(q.dequeue() == 1);

}
TEST_CASE("Testing Graph.get_size()"){
  Graph g(3);
  CHECK(3 == g.get_size());
  CHECK(4 == g.get_size());
}

TEST_CASE("Testing Graph.get_edge_num()"){
  Graph g(3);

  CHECK(0 == g.get_edge_num());
  g.addEdge(0,1);
  CHECK(1 == g.get_edge_num());
  g.removeEdge(0,1);
  CHECK(0 == g.get_edge_num());
}

TEST_CASE("Testing Algorithms.bfs"){
  Graph g(3);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(2,0);

  Graph check(3);
  check.addEdge(0,1);
  check.addEdge(1,2);

  Graph bfs_tree = Algorithms::bfs(g,0);

  LinkedList** g_lst = g.get_vetrex_list();
  LinkedList** bfs_lst = bfs_tree.get_vetrex_list();

  for (int i = 0; i < g.get_size();i++){
    Node* n_g_lst = g_lst[i]->get_head();
    Node* n_bfs_lst = bfs_lst[i]->get_head();

    while (nullptr != n_g_lst && nullptr != n_bfs_lst){
      CHECK(n_g_lst->node_number == n_bfs_lst->node_number);
      CHECK(n_g_lst->weight == n_bfs_lst->weight);
	  n_g_lst = n_g_lst->next;
      n_bfs_lst = n_bfs_lst->next;
    }
  }
}


TEST_CASE("Testing Algorithms.dfs"){
  Graph g(3);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(2,0);

  Graph check(3);
  check.addEdge(0,1);
  check.addEdge(1,2);

  Graph dfs_tree = Algorithms::dfs(g,0);

  LinkedList** g_lst = g.get_vetrex_list();
  LinkedList** dfs_lst = dfs_tree.get_vetrex_list();

  for (int i = 0; i < g.get_size();i++){
    Node* n_g_lst = g_lst[i]->get_head();
    Node* n_dfs_lst = dfs_lst[i]->get_head();

    while (nullptr != n_g_lst && nullptr != n_dfs_lst){
      CHECK(n_g_lst->node_number == n_dfs_lst->node_number);
      CHECK(n_g_lst->weight == n_dfs_lst->weight);
	  n_g_lst = n_g_lst->next;
      n_dfs_lst = n_dfs_lst->next;
    }
  }
}

