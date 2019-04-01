#ifndef SEARCH_H
#define SEARCH_H

#include "node.h"
#include <queue>
#include <set>
#include <unistd.h>

class Search {
private:
    //comparator for the set
    struct cmp {
        bool operator() (Node a, Node b) const {
            for(int i=0; i<5;i++) {
                for(int j=0; j<4; j++){
                    if(a.getState().getElement(i, j) != b.getState().getElement(i, j)) {
                        return true;
                    }
                }
            }

            return false;
        }
    };

    std::queue<Node> frontier;
    std::set<Node> visited;

public:
    Search();
    void addToQueue(Node node);
    bool addToVisited(Node node);
    void search();
    bool isGoalState(Node node);
};

#endif /* SEARCH_H */