#ifndef SEARCH_H
#define SEARCH_H

#include "node.h"
#include <queue>
#include <deque>
#include <unistd.h>

class Search {
private:
    std::queue<Node> frontier;
    std::deque<Node> visited;

public:
    Search();
    void addToQueue(Node node);
    void addToVisited(Node node);
    Node search();
    bool isGoalState(Node node);
};

#endif /* SEARCH_H */