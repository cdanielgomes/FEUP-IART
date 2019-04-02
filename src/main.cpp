#include "search.h"
#include "DFS.h"
#include "astar.h"

using namespace std;

int main() {


    vector<vector<int>> initialBoard = {
            {1,  6, 7, 2},
            {3,  9, 10, 4},
            {5,  -1, -1,  8},
            {5,  -1, -1, 8},
            {0, 11, 12,  0}
    };

    pair<int, int> empty1(4, 0); // coordinates of initial empty space
    pair<int, int> empty2(4, 3); // coordinates of the other initial empty space

    State initialState(initialBoard, empty1, empty2);

    Node * root = new Node(initialState, nullptr, 0, 0);

    /* Depth First Search */
    // DFS dfs = DFS(root);
    // dfs.solve();

    /* A* */
    // astar a(root);
    // a.solve();

    /* Breadth First Search */
    // Search search = Search();
    // search.addToQueue(root);
    // search.search();
}

/*

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFSIterative(2);
    //g.DFS(2);

    return 0;
}*/
