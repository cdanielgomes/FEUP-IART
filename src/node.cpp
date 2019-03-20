#include "node.h"

using namespace std;

Node::Node(vector<vector<int>> state, Node * parentNode, int depth, int pathCost) : parentNode(parentNode), depth(depth), pathCost(pathCost), state(move(state)) {}