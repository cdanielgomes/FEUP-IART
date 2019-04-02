#ifndef FEUP_IART_ASTAR_H
#define FEUP_IART_ASTAR_H


#include <queue>
#include "node.h"
#include <math.h>
#include <bits/unordered_set.h>

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
class astar {

private:

    struct cmp {
        bool operator()(Node * lhs, Node * rhs) const {
            return lhs->getCost() > rhs->getCost();
        }
    };


    std::priority_queue<Node *, std::vector<Node *>, cmp> nodesExplore;
    std::unordered_set<Node *> visited;
    Node * initialState;


    double heuristic(Node * node);

    bool childrenNode(Node * n, bool a);

    double nearToEmpties(Node * n);

    bool find(Node * h);


public:

    astar(Node * initial);

    void solveAStar();
    void solveGreedy();
    void solve(bool solve);

};


#endif //FEUP_IART_ASTAR_H
