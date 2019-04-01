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
        bool operator()(Node * lhs, Node * rhs) const {
            return lhs->getCost() > rhs->getCost();
        }
    };


    std::priority_queue<Node *, std::vector<Node *>, cmp> nodesExplore;
    std::vector<Node *> visited;
    Node * initialState;


    double heuristic(Node * node);

    void childrenNode(Node * n);

    double nearToEmpties(Node * n);

    bool find(Node * h);


public:

    astar(Node * initial);

    void solve();


};


#endif //FEUP_IART_ASTAR_H
