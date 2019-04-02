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

Node * Search::search() {
    int iteration = 0;

    while(true) {
        cout << "Iteration " << iteration++ << ":" << endl;

        Node * node = this->frontier.front();
        this->frontier.pop();

        if(!expand(node, node->getParent())){
            cout << "preciso disto\n";
            continue;
        }

        cout << node->getDepth() << endl;

        node->printState();

        if(isGoalState(node)) {cout << "Got it\n"; return node;}

        auto children = node->getChildren();
        for(auto child : children) {
            addToQueue(child);
        }
        
    }

}