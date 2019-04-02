#include "search.h"

using namespace std;

Search::Search() {}

bool Search::expand(Node * node, Node * ancestor) {
    if(ancestor == nullptr){ // reached root
        return true;
    }

    if(ancestor->equal(node)){ // this node has already been created in this branch
        return false;
    }

    return expand(node, ancestor->getParent());
}

void Search::addToQueue(Node * node) {

    if(expand(node, node->getParent())) {
        this->frontier.push(node);
    }
}

bool Search::isGoalState(Node * node) {
    for(int x=3; x<5;x++) {
        for(int y=1; y<3; y++) { //goal positions
            if(node->getState().getElement(x, y) != -1) {
                return false;
            } 
        }
    }

    return true;
}

void Search::search() {
    int iteration = 1;

    while(true) {
        Node * node = this->frontier.front();
        this->frontier.pop();

        if(!expand(node, node->getParent())){
            continue;
        }
        iteration++;

        if(isGoalState(node)) {cout << "Got it\n"; this->leaf = node; return;}

        auto children = node->getChildren();
        for(auto child : children) {
            addToQueue(child);
        }
    }

}

void Search::printSolution() {
    deque<Node *> solution;

    solution.push_back(this->leaf);
    Node * parent = this->leaf->getParent();
    
    while(parent != nullptr) {
        solution.push_back(parent);
        parent = parent->getParent();
    }

    cout << "Solution:\n";
    while(!solution.empty()) {
        parent = solution.back();
        solution.pop_back();
        parent->printState();
    }
}