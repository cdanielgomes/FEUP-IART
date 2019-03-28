#ifndef NODE_H
#define NODE_H

#include "state.h"

/* 
    A seguir a estrutura dos slides de solving search 
    página 4
*/

class Node {

private:
    State state;
    Node * parentNode;
    // operator
    int depth;
    int pathCost;
    int cost;


public:
    Node(State state, Node * parentNode, int depth, int pathCost);
    Node(State state, Node * parentNode, int depth, int pathCost, int cost);
    Node();
    void printState();
    State getState();
    std::vector<Node> getChildren();
    Node * getParent();
    int getCost();
    int getDepth();
    int getPathCost();
};

#endif /* NODE_H */

