//
// Created by daniel on 27-03-2019.
//

#ifndef FEUP_IART_ASTAR_H
#define FEUP_IART_ASTAR_H


#include <queue>
#include "node.h"
#include <math.h>


class astar {

private:

    struct cmp {
        bool operator() (Node lhs, Node rhs) const {
            return lhs.getCost() < rhs.getCost();
        }
    };


    std::priority_queue<Node, std::vector<Node>, cmp> nodesExplore;
    std::vector<Node> path;
    State initialState;

    void calculateCost(Node &node);

    int nearTofinal(Node &node);

    int manhattam(Node &node);

    int euclidean(Node &node);

    int heuristic(Node &node);
    void childrenNode(Node &n);

    bool find(Node &h);


public:

    astar(State initial);

    void solve();


};


#endif //FEUP_IART_ASTAR_H
