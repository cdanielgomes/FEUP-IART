#include "DFS.h"
#include <algorithm>

using namespace std;

DFS::DFS(Node *n, int max) {

    this->max = max;
    this->initialNode = n;
    this->frontier.push(n);

}

bool DFS::find(Node *h) {

    auto it = this->visited.insert(h);

    if (!it.second) {
        return true;
    } else false;
}

void DFS::addStack(Node *n) {

    if (n->getDepth() <= deep) {
        for (auto i : n->getState().getChildren()) {
            Node *node = new Node(i, n, n->getDepth() + 1);
            this->frontier.push(node);
        }
    }
}


Node *DFS::solve() {
    int iteration = 0;

    if (initialNode->getState().endState()) { cout << "Started with a solution\n"; }

    while (this->deep <= this->max) {

        while (!this->frontier.empty()) {

            auto node = this->frontier.top();

            this->frontier.pop();

            if (find(node)) {
                delete (node);
                continue;
            }

            if (node->getState().endState()) return node;
            this->visited.insert(node);


            cout << "Iteration " << iteration++ << ":" << endl;

            node->printState();

            this->addStack(node);
        }


        this->visited.clear();
        this->frontier.push(this->initialNode);

        this->deep += 1;
    }

    cout << "terminou com o depth = " << this->deep << " e o max " << this->max << endl;

}

void DFS::printPath(Node *n) {

    vector<Node *> a;
    Node *b;
    while (!n->equal(initialNode)) {

        b = n->getParent();

        a.push_back(b);
        n = b;
    }

    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        (*it)->printState();
        std::cout << std::endl;
    }
}


/*
void DFS::DFSaux(Node n, bool visited[], int pathCost) {

    if (cost > maxplays) {
        return;
    }

    visited[n] = true; //Mark the current node as visited
    cout << n << " ";

    //Recur for all the vertices adjacent to this vertex
    //To link to game -> subst adj by all possible plays
    pair<int, int>::iterator i;
    for (i = adj.begin(); i != adj.end(); i++)
        if (!visited[*i])
            DFSaux(*i, visited, pathCost + 1);
}

//Uses DFSaux recursivly

void DFS::DFS(Node n) {


    //Mark all the vertices as not visited
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    // Call the recursive aux function to print DFS
    DFSaux(n, visited, 1);
}


void DFS::DFSIterative(Node n) {

    while (!isGoalState(n)) {
        DFS(n);
    }
}
*/

