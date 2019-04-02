#include "node.h"

using namespace std;

Node::Node(State state, Node *parentNode, int depth, int pathCost) : parentNode(parentNode), depth(depth),
                                                                     pathCost(pathCost), state(move(state)) {}

Node::Node(State state, Node *parentNode, int depth, int pathCost, int cost) : parentNode(parentNode), depth(depth),
                                                                               pathCost(pathCost), state(move(state)),
                                                                               cost(cost) {}

Node::Node() {};


Node::Node(State state, Node *parentNode, int depth) : state(state), depth(depth), parentNode(parentNode) {}


void Node::printState() {
    this->state.printState();
    std::cout << "cost: " << (float)this->cost << std::endl;

}

State Node::getState() const {
    return this->state;
}

vector<Node *> Node::getChildren() {
    vector<Node*> children;

    vector<State> childrenStates = this->state.getChildren();

    for(auto state : childrenStates) {
        Node * child = new Node(state, this, this->depth + 1, 1, this->cost + 1);
        children.push_back(child);
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

bool Node::equal(Node * rhs) {

    vector<vector<int>> board1 = rhs->getState().getBoard();

    for(int x = 0; x < 5; x++)
        for(int y = 0; y < 4; y++){

            if(this->state.getBoard()[x][y] != board1[x][y]){

                return false;
            }
        }

    return true;
}

void Node::setCost(int i) {
    this->cost = i;
}
