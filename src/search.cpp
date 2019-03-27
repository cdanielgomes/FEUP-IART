#include "search.h"

using namespace std;

Search::Search() {}

bool Search::addToVisited(Node node) {
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
    int iterations = 0;

    while(!this->frontier.empty()) {
        cout << "Iteration " << iterations++ << ":" << endl;

        Node node = this->frontier.front();
        this->frontier.pop();

        node.printState();
        if(isGoalState(node)) {return;}

        node.getChildren();
    }

}