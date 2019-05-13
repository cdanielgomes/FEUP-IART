#ifndef SEARCH_H
#define SEARCH_H

#include "node.h"
#include <queue>
#include <deque>
#include <unistd.h>

class Search {
private:
    std::queue<Node *> frontier;
    Node * leaf;
public:
    Search();
    void addToQueue(Node * node);
    void search();
    void printSolution();
    bool isGoalState(Node * node);
    bool expand(Node * node, Node * ancestor);
};

#endif /* SEARCH_H */