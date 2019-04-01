#include "node.h"

using namespace std;

Node::Node(State state, Node *parentNode, int depth, int pathCost) : parentNode(parentNode), depth(depth),
                                                                     pathCost(pathCost), state(move(state)) {}

Node::Node(State state, Node *parentNode, int depth, int pathCost, int cost) : parentNode(parentNode), depth(depth),
                                                                               pathCost(pathCost), state(move(state)),
                                                                               cost(cost) {}

Node::Node() {};

void Node::printState() {
    this->state.printState();
}

State Node::getState() const {
    return this->state;
}

vector<Node> Node::getChildren() {
    vector<Node> children;

    vector<State> childrenStates = this->state.getChildren();

    for(auto state : childrenStates) {
        children.push_back(Node(state, this, ++this->depth, 1, this->cost + 1));
    }

    return children;
}

Node *Node::getParent() {
    return this->parentNode;
}


int Node::getCost() {
    return this->cost;
}

int Node::getDepth() {
    return this->depth;
}

int Node::getPathCost() {
    return this->pathCost;
}

bool Node::equal(Node &rhs) {
    return this->state.getBoard() == rhs.getState().getBoard();
}