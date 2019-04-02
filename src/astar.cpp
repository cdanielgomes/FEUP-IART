#include "astar.h"
#include <algorithm>

astar::astar(Node *initial) {
    this->initialState = initial;
}

double euclidean_distance(int x, int x2, int y, int y2) {
    return sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
}

double manhattam_distance(int x, int x2, int y, int y2) {
    return abs(x2 - x) + abs(y2 - y);
}

std::pair<int, int> md(Node &node) {
    auto b = node.getState().getBlock(-1).getBros();

    return std::pair<double, double>((b[2].first + b[0].first) / 2.0, ((b[2].second + b[0].second) / 2.0));

}

int nPiecesBetween(Node &node) {
    auto leftP = node.getState().getBlock(-1).getBros()[2];
    auto rightP = node.getState().getBlock(-1).getBros()[3];
    auto board = node.getState().getBoard();
    int nPieces = 0;
    for (int x = 0; x + rightP.first < board[1].size(); x++) {
        if (board[leftP.first + x][leftP.second] != 0) nPieces++;
        if (board[rightP.first + x][rightP.second] != 0) nPieces++;
    }

    return nPieces;
}

int nPiecesAcima(Node &node) {
    auto leftP = node.getState().getBlock(-1).getBros()[0];
    auto rightP = node.getState().getBlock(-1).getBros()[1];
    auto board = node.getState().getBoard();
    int nPieces = 0;
    for (int x = 0; rightP.first - x > -1; x++) {
        if (board[leftP.first - x][leftP.second] != 0) nPieces++;
        if (board[rightP.first + x][rightP.second] != 0) nPieces++;
    }

    return nPieces;
}


double emptyAdjacent(Node &n) {

    auto empties = n.getState().getEmpties();
    auto board = n.getState().getBoard();
    double mult = 1;

    int y1 = empties.front().second;
    int x1 = empties.front().first;

    int y2 = empties.back().second;
    int x2 = empties.back().first;

    if (x1 + 1 <= 4) {

        if (board[x1 + 1][y1] == -1) {

            mult *= 0.5;
        }
    }

    if (x2 + 1 <= 4) {
        if (board[x2 + 1][y2] == -1) {
            mult *= 0.5;

        }
    }


    // ------------------ em Y -----------------

    /* if (y1 - 1 >= 0) {
         if (board[x1][y1 - 1] == -1) mult *= 0.90;
     }

     if (y2 - 1 >= 0) {
         if (board[x2][y2 - 1] == -1) mult *= 0.90;
     }

     if (y1 + 1 <= 3) {
         if (board[x1][y1 + 1] == -1) mult *= 0.90;
     }

     if (y2 + 1 <= 3) {
         if (board[x2][y2 + 1] == -1) mult *= 0.90;
     }*/


    return mult;
}

double astar::nearToEmpties(Node *node) {

    State state = node->getState();
    auto k = md(*node);

    double sum = 0;


    sum += -k.first + state.getEmpties()[0].first;
    sum += -k.first + state.getEmpties()[1].first;

//    sum = euclidean_distance(k.first, state.getEmpties()[0].first, k.second, state.getEmpties()[0].second);
    //  sum += euclidean_distance(k.first, state.getEmpties()[1].first, k.second, state.getEmpties()[1].second);

    return sum;
}

double astar::heuristic(Node *node) {
    auto b = node->getState().getBlock(-1).getBros();
//near to final position
    //return euclidean_distance(b.front().first, 3, b.front().second, 1) + manhattam_distance(b.front().first, 3, b.front().second, 1);
    //  return euclidean_distance(b.front().first, 3, b.front().second, 1);
    return manhattam_distance(b.front().first, 3, b.front().second, 1) +
           euclidean_distance(b.front().first, 3, b.front().second, 1);


}

bool astar::childrenNode(Node *n, bool a) {
    auto k = n->getState().getChildren();
    for (auto i : k) {
        Node *child = new Node(i, n, n->getDepth() + 1, n->getPathCost() + 1);

        int l;
        if (a) {
            l = this->heuristic(child) + nPiecesBetween(*child) + child->getPathCost();
        } else
            l = this->heuristic(child) + nPiecesBetween(*child);

        (child)->setCost(l);

        this->nodesExplore.push(child);

    }
}

void astar::solveAStar() {
    solve(true);

}

void astar::solveGreedy() {
    solve(false);
}

void astar::solve(bool s) {
    this->childrenNode(this->initialState, s);

    Node *n;

    //int i = 0;

    std::cout << "Calculating ...." << std::endl;

    do {

// node with least cost to explore

        n = this->nodesExplore.top();
        this->nodesExplore.pop();


        if (n->getState().endState()) break;


        if (find(n)) {
            this->nodesExplore.pop();
            delete(n);
            continue;
        }

      //  n->printState();

        this->visited.insert(n);

        this->childrenNode(n, s);
//i++;
    } while (!this->nodesExplore.empty());

    //backtrack to the initial node
    Node *b;
    std::vector<Node *> a;
    a.push_back(n);

    while (!n->equal(initialState)) {

        b = n->getParent();

        a.push_back(b);
        n = b;

    }
/*
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        (*it)->printState();
        std::cout << std::endl;
    }
*/
    std::cout << "Necessary moves: " << a.size() << std::endl;

}


bool astar::find(Node *h) {

    auto it = this->visited.insert(h);

    if (!it.second) {
        return true;
    } else false;
}

