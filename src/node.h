#include <vector>

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

public:
    Node(std::vector<std::vector<int>> state, Node * parentNode, int depth, int pathCost);
};

