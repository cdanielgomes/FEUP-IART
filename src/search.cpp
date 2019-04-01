#include "search.h"

using namespace std;

Search::Search() {}

void Search::addToVisited(Node node) {
    this->visited.push_front(node);
}

void Search::addToQueue(Node node) {
    for(auto known : this->visited) {
       if(known.getState().getBoard() == node.getState().getBoard()){
           return;
       }
    }

    this->frontier.push(node);
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

Node Search::search() {
    int iteration = 0;

    while(true) {
        cout << "Iteration " << iteration++ << ":" << endl;

        Node node = this->frontier.front();
        this->frontier.pop();
        addToVisited(node);
        node.printState();
        if(isGoalState(node)) {cout << "Got it\n"; return node;}

        vector<Node> children = node.getChildren();
        for(auto node : children) {
            addToQueue(node);
        }

    }

}