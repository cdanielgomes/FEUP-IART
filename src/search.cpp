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

void Search::search() {
}