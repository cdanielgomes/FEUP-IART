#ifndef DSF_H
#define DSF_H

#include "search.h"
#include "state.h"
#include <iostream>
#include <list>

class Graph {

private:

  int V; // No. of vertices
  list<int> *adj; // Pointer to an array containing adjacency lists
  void DFSaux(int v, bool visited[]); // A function used by DFS


public:

  Graph(int V); // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	void DFS(); // prints DFS of the complete graph

};

#endif /* DFS_H */
