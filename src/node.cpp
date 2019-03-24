#include "node.h"

using namespace std;

Node::Node(vector<vector<int>> state, Node * parentNode, int depth, int pathCost) : parentNode(parentNode), depth(depth), pathCost(pathCost), state(move(state)) {}

void Node::printState() {

    for(auto line=this->state.begin(); line!=this->state.end(); line++) {
        for(auto column=(*line).begin(); column!=(*line).end(); column++) {
            cout << setw(5) << *column << "|";
        }
        cout << endl;
    }
}

void Node::setEmpties(pair<int, int> empty1, pair<int, int> empty2) {
    this->empty1 = empty1;
    this->empty2 = empty2;
}