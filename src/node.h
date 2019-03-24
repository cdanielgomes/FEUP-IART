#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <utility>

/* 
    A seguir a estrutura dos slides de solving search 
    página 4
*/

class Node {

private:
    std::vector<std::vector<int>> state;
    Node * parentNode;
    // operator
    int depth;
    int pathCost;

    std::pair<int, int> empty1;
    std::pair<int, int> empty2;

public:
    Node(std::vector<std::vector<int>> state, Node * parentNode, int depth, int pathCost);

    void printState();
    void setEmpties(std::pair<int, int> empty1, std::pair<int, int> empty2);
    
};

#endif /* NODE_H */

