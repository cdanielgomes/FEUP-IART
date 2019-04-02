#include "node.h"

using namespace std;

Node::Node(State state, Node *parentNode, int depth, int pathCost) : parentNode(parentNode), depth(depth),
                                                                     pathCost(pathCost), state(move(state)) {}

Node::Node() {};


Node::Node(State state, Node *parentNode, int depth) : state(state), depth(depth), parentNode(parentNode) {}


void Node::printState() {
    this->state.printState();
    std::cout << "cost: " << (float)this->cost << std::endl;
    std::cout << "depth: " << this->depth << std::endl;
    std::cout << "pathCost: " << (float)this->pathCost << std::endl;

}

State Node::getState() {
    return this->state;
}

vector<Node> Node::getChildren() {
    vector<Node> children;

    this->state.getChildren();

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
/*
    for(int x = 0; x < 5; x++)
        for(int y = 0; y < 4; y++){

            if(this->state.getBoard()[x][y] != board1[x][y]){

                return false;
            }
        }*/

    return this->state.getBoard() == board1;
}

void Node::setCost(int i) {
    this->cost = i;
}

string const Node::toString() {
    string a;

    for(auto i : this->state.getBoard()){
        for(auto j : i){
            a.append(std::to_string(j));
        }
    }
    return a;
}