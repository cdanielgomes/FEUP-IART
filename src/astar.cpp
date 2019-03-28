//
// Created by daniel on 27-03-2019.
//

#include "astar.h"
#include <algorithm>

astar::astar(State initial) : initialState(initial) {}


int astar::nearTofinal(Node &node) {



}

int astar::euclidean(Node &node) {
    auto b = node.getState().getBlock(-1).getBros();
    int sum = sqrt((3 - b[0].first) * (3 - b[0].first) + (1 - b[0].second) * (1 - b[0].second));
    sum += sqrt((3 - b[1].first) * (3 - b[1].first) + (2 - b[1].second) * (2 - b[1].second));
    sum += sqrt((4 - b[2].first) * (4 - b[2].first) + (1 - b[2].second) * (1 - b[2].second));
    sum += sqrt((4 - b[3].first) * (4 - b[3].first) + (2 - b[3].second) * (2 - b[3].second));

    return sum;
}

int astar::manhattam(Node &node) {
    auto b = node.getState().getBlock(-1).getBros();
    int sum = abs(3 - b[0].first) + abs(1 - b[0].second);
    sum += abs(3 - b[1].first) + abs(2 - b[1].second);
    sum += abs(4 - b[2].first) + abs(1 - b[2].second);
    sum += abs(4 - b[3].first) + abs(2 - b[3].second);

    return sum;

}

int astar::heuristic(Node &node) {
    return euclidean(node) + manhattam(node);
}

void astar::childrenNode(Node &n) {
    auto k = n.getState().getChildren();

    for (auto i : k) {
        Node *lmao = new Node(i, &n, n.getDepth() + 1, n.getPathCost() + 1, n.getPathCost() + 1 + this->heuristic(n));
        this->nodesExplore.emplace(*lmao);
    }
}

void astar::solve() {
    Node firstN(this->initialState, nullptr, 0, 0, 0);
    this->childrenNode(firstN);

    Node n;

    do {
        n = this->nodesExplore.top();

        if (find(n)) {
            this->nodesExplore.pop();
            continue;
        }
        n.getState().printState();
        this->path.push_back(n);
        this->childrenNode(n);

    } while (!n.getState().endState());

}

bool astar::find(Node &h) {
    for (auto i : this->path) {
        if (i.equal(h))
            return true;
    }
}