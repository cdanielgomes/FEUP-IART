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
    
    int depth;
    int pathCost; //used in a* e  greedy
    double cost; // used in a* e  greedy
    std::vector<Node *> * childs;


public:
    Node(State state, Node * parentNode, int depth, int pathCost);
    Node();
    Node(State state, Node * parentNode, int depth, int pathCost, double cost);

    Node(State state, Node * parentNode, int depth);
    void printState();
    State getState() const;
    std::vector<Node *> getChildren();
    Node * getParent();
    int getCost();
    int getDepth();
    int getPathCost();
    bool equal(Node * rhs);
    void setCost(int i);
    std::string const toString();
    std::vector<Node *> * getChilds();

};

#endif /* NODE_H */

