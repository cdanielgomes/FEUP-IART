#include "search.h"

using namespace std;

Search::Search() {}

bool Search::expand(Node *node, Node *ancestor) {
    if (ancestor == nullptr) { // reached root
        return true;
    }

    if (ancestor->equal(*node)) { // this node has already been created in this branch
        return false;
    }

    return expand(node, ancestor->getParent());
}

bool Search::addToQueue(Node *node) {
    State visitedState = node->getState();

    for (auto i : visitedState.getChildren()) {
        Node *n = new Node(i, node, node->getDepth() + 1, node->getPathCost() + 1);
        if (!find(n)) {
            if (n->getState().endState()) {
                return true;
            }
            else
                this->frontier.push(n);
        }

    }

    /*
if(expand(node, node->getParent())) {
    this->frontier.push(node);
}*/
}

bool Search::isGoalState(Node *node) {
    for (int x = 3; x < 5; x++) {
        for (int y = 1; y < 3; y++) { //goal positions
            if (node->getState().getElement(x, y) != -1) {
                return false;
            }
        }
    }

    return true;
}

/*
Node * Search::search() {
    int iteration = 0;

    while(true) {
        cout << "Iteration " << iteration++ << ":" << endl;

        Node * node = this->frontier.front();
        this->frontier.pop();

        if(!expand(node, node->getParent())){
            continue;
        }

        //if(iteration > 13000)
            node->printState();

        if(isGoalState(node)) {cout << "Got it\n"; return node;}

        auto children = node->getChildren();
        for(auto child : children) {
            addToQueue(node);
        }
        
    }

}*/

Node *Search::search() {
    int iteration = 0;

    Node *n = frontier.front();
    frontier.pop();
    addToQueue(n);

    cout << "while \n";
    while (!frontier.empty()) {


        n = this->frontier.front();
        this->explored.push_back(n);
        this->frontier.pop();

        cout << "Iteration " << iteration++ << ":" << endl;

        /*if(!expand(node, node->getParent())){
            continue;
        }*/

        //if(iteration > 13000)
        n->printState();

        if(this->addToQueue(n)){
            return n;
        }

    }

    cout << "NO SOLUTION\n";

}

bool Search::find(Node *h) {
    for (auto i : this->explored) {
        if (i->equal(*h))
            return true;
    }

    std::queue<Node *> auxList1 = frontier;
    std::queue<Node *> auxList2;

    while (!auxList1.empty()) {

        Node *l = auxList1.front();
        if (l->equal(*h))
            return true;

        auxList1.pop();
    }

    return false;
}
