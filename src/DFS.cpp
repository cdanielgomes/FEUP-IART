#include "DFS.h"
#include <algorithm>

using namespace std;

DFS::DFS(Node *n) {

    this->initialNode = n;

}

void DFS::solve() {
    Node *node = this->recursive(this->initialNode);

    if (nullptr == node)
        cout << "No solution\n";
    else printPath(node);

}

void DFS::printPath(Node *n) {

    vector<Node *> a;
    Node * b;
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

Node *DFS::recursive(Node *n) {

    for (auto i : n->getState().getChildren()) {

        if (i.endState())
            return new Node(i, n, n->getDepth() + 1);

        Node *nNode = new Node(i, n, n->getDepth() + 1);

        if (this->find(nNode)){
            continue;
        }


        nNode->printState();

        this->visited.push_back(nNode);
        Node * x = recursive(nNode);


       if(x == nullptr)
           return nullptr;
       else x;

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

bool DFS::find(Node *h) {

    for (auto i : this->visited) {

        if (i->equal(h)){
            return true;

        }
    }
}

