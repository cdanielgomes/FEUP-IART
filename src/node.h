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


public:
    Node(State state, Node * parentNode, int depth, int pathCost);
    void printState();
    
};

#endif /* NODE_H */

