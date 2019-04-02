//#include "search.h"
//#include "DFS.h"
#include "astar.h"
#include <chrono>

using namespace std;

int main() {


    vector<vector<int>> initialBoard = {
            {1,  -1, -1, 2},
            {3,  -1, -1, 5},
            {3,  8,  11,  6},
            {4,  9,  10, 7},
            {4, 0,  0,  7}
    };

    pair<int, int> empty1(4, 1); // coordinates of initial empty space
    pair<int, int> empty2(4, 2); // coordinates of the other initial empty space

    State initialState(initialBoard, empty1, empty2);

    //
    //Node root(initialState, nullptr, 0, 0);


    Node *root = new Node(initialState, nullptr, 0, 0);
    auto start = std::chrono::high_resolution_clock::now();

    //DFS dfs = DFS(root, 40);

     // dfs.solve();

     astar a(root);
    a.solveAStar();
    auto end = std::chrono::high_resolution_clock::now();

    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

    cout << "DURATION: " << time << "ms";

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
