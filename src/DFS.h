#ifndef DSF_H
#define DSF_H

#include "search.h"
#include "state.h"
#include "node.h"
#include <iostream>
#include <list>

class DFS {

private:

    //Node n;
    //int V; // No. of vertices
    //std::list<int> *adj; // Pointer to an array containing adjacency lists
    //void DFSaux(int v, bool visited[],int cost); // A function used by DFS
    void DFSaux(Node n, bool visited[],int pathCost);
    std::vector<Node *> visited;
    Node * initialNode;
public:

    //Graph(int v); // Constructor
    Node * recursive(Node *n);
    DFS(Node * n);
    void addEdge(int v, int w); // function to add an edge to graph
    //void DFS(Node n);
    //void DFS(int v); // prints DFS of the complete graph
    void DFSIterative(Node n);
    bool find(Node * h);
    void printPath(Node * n);
    void solve();
    //void DFSIterative(int v);

};

#endif /* DFS_H */
