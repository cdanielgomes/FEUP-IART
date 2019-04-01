#ifndef DSF_H
#define DSF_H

#include "search.h"
#include "state.h"
#include <iostream>
#include <list>

class Graph {

private:

    int V; // No. of vertices
    std::list<int> *adj; // Pointer to an array containing adjacency lists
    void DFSaux(int v, bool visited[],int cost); // A function used by DFS


public:

    Graph(int v); // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void DFS(int v); // prints DFS of the complete graph
    void DFSIterative(int v);

};

#endif /* DFS_H */
