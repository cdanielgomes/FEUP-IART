#include "node.h"

using namespace std;

Node::Node(State state, Node * parentNode, int depth, int pathCost) : parentNode(parentNode), depth(depth), pathCost(pathCost), state(move(state)) {}

void Node::printState() {
    this->state.printState();
}

State Node::getState() {
    return this->state;
}