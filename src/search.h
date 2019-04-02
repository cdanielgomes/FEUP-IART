#ifndef SEARCH_H
#define SEARCH_H

#include "node.h"
#include <queue>
#include <deque>
#include <unistd.h>

class Search {
private:
    std::queue<Node *> frontier;
    std::vector<Node *> explored;
public:
    Search();
    bool addToQueue(Node * node);
    Node * search();
    bool isGoalState(Node * node);
    bool expand(Node * node, Node * ancestor);
    bool find(Node * h);
};

#endif /* SEARCH_H */