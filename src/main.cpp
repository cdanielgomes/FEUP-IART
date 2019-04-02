#include "search.h"
//#include "DFS.h"
#include "astar.h"
#include "node.h"
#include <chrono>

using namespace std;

int main() {


    vector<vector<int>> initialBoard = {
            {1,  8, 11, 2},
            {3,  9, 10, 5},
            {3,  -1,  -1,  6},
            {4,  -1,  -1, 7},
            {0, 12,  13,  0}
    };

    pair<int, int> empty1(4, 0); // coordinates of initial empty space
    pair<int, int> empty2(4, 3); // coordinates of the other initial empty space

    State initialState(initialBoard, empty1, empty2);
    Node * root = new Node(initialState, nullptr, 0, 0, 0);
    root->getState().setOp(-1);

    auto start = std::chrono::high_resolution_clock::now();

    /* A* */
    // astar a(root);
    // a.solveAStar();

    /* BFS */
    Search bfs = Search();
    bfs.addToQueue(root);
    bfs.search();

    auto end = std::chrono::high_resolution_clock::now();

    bfs.printSolution();

    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

    cout << "DURATION: " << time << "ms\n";

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
