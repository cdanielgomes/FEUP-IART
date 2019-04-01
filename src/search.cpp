#include "search.h"

using namespace std;

Search::Search() {}

bool Search::addToVisited(Node node) {
    bool equal = true;

    for(auto known : this->visited) {
        for(int i=0; i<5;i++) {
            for(int j=0; j<4; j++){
                if(known.getState().getElement(i, j) != node.getState().getElement(i, j)) {
                    equal = false;
                }
            }
        }
        if(equal) {
            return false;
        }
        equal = true;
    }

    return this->visited.insert(node).second;
}

void Search::addToQueue(Node node) {
    if(addToVisited(node)) { // added -> hasn't visited node before
        this->frontier.push(node);
    }
}

bool Search::isGoalState(Node node) {
    for(int x=3; x<5;x++) {
        for(int y=1; y<3; y++) { //goal positions
            if(node.getState().getElement(x, y) != -1) {
                return false;
            } 
        }
    }

    return true;
}

void Search::search() {
    int iteration = 0;

    while(!this->frontier.empty()) {
        cout << "Iteration " << iteration++ << ":" << endl;

        Node node = this->frontier.front();
        this->frontier.pop();
        node.printState();
        if(isGoalState(node)) {cout << "Got it\n"; return;}

        vector<Node> children = node.getChildren();
        for(auto node : children) {
            addToQueue(node);
        }
    }

}