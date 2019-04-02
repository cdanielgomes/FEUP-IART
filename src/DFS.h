#ifndef DSF_H
#define DSF_H

#include "search.h"
#include "state.h"
#include "node.h"
#include <iostream>
#include <list>
#include <bits/unordered_set.h>
#include <stack>


namespace std {
    template<>
    struct hash<Node *> {
        size_t
        operator()(Node *obj) const {
            return hash<string>()(obj->toString());
        }
    };
}


namespace std {
    template<>
    struct equal_to<Node *> {
        bool
        operator()(Node *obj, Node *obj2) const {
            return obj->equal(obj2);
        }
    };
}

class DFS {

private:

    //Node n;
    //int V; // No. of vertices
    //std::list<int> *adj; // Pointer to an array containing adjacency lists
    //void DFSaux(int v, bool visited[],int cost); // A function used by DFS
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
    //void DFS(Node n);
    //void DFS(int v); // prints DFS of the complete graph
    void DFSIterative(Node n);
    bool find(Node * h);
    void printPath(Node * n);
    Node * solve();
    void addStack(Node * n);

    //void DFSIterative(int v);

};

#endif /* DFS_H */
