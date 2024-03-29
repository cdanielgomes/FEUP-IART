#include "node.h"

using namespace std;

Node::Node(State state, Node *parentNode, int depth, int pathCost) : parentNode(parentNode), depth(depth),
                                                                     pathCost(pathCost), state(move(state)) {}

Node::Node() {}


Node::Node(State state, Node *parentNode, int depth) : state(state), depth(depth), parentNode(parentNode) {}

Node::Node(State state, Node * parentNode, int depth, int pathCost, double cost) :  parentNode(parentNode), depth(depth),
pathCost(pathCost), state(move(state)), cost(cost) {}


void Node::printState() {
    this->state.printState();
    std::cout << "cost: " << (float)this->cost << std::endl;
    std::cout << "depth: " << this->depth << std::endl;
    std::cout << "pathCost: " << (float)this->pathCost << std::endl << std::endl;

}

State Node::getState() const {
    return this->state;
}

vector<Node *> Node::getChildren() {
    vector<Node*> children;

    vector<State> childrenStates = this->state.getChildren();

    for(auto state : childrenStates) {
        Node * child = new Node(state, this, this->depth + 1, this->pathCost + this->cost, this->cost + 1);
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

void Node::setCost(int i) {
    this->cost = i;
}

bool Node::equal(Node * rhs) {
    return (this->state.getBoard() == rhs->getState().getBoard());
}

string const Node::toString(){
    string a;

    for(auto i : this->state.getBoard()){
        for (auto j : i){
            a.append(to_string(j));

        }
    }
    return a;
}