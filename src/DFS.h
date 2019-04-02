#ifndef DSF_H
#define DSF_H

#include "search.h"
#include "state.h"
#include "node.h"
#include <iostream>
#include <list>
#include <bits/unordered_set.h>
#include <stack>
#include "common.h"

class DFS {

private:

    void DFSaux(Node n, bool visited[],int pathCost);
    std::stack<Node *> frontier;
    std::unordered_set<Node *> visited;
    Node * initialNode;
    int deep = 5;
    int max;
public:

    //Graph(int v); // Constructor
    Node * recursive(Node *n);
    DFS(Node * n, int max);
    void addEdge(int v, int w); // function to add an edge to graph
    //void
    void DFSIterative(Node n);
    bool find(Node * h);
    void printPath(Node * n);
    Node * solve();
    void addStack(Node * n);

    //void DFSIterative(int v);

};

#endif /* DFS_H */
