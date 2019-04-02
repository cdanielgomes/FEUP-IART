<<<<<<< HEAD
//#include "search.h"
=======

#include "search.h"
>>>>>>> 2d35b5b6e993c3e7e072fe710783180d50d39e8a
#include "DFS.h"
#include "astar.h"
#include <chrono>

using namespace std;

int main() {


    vector<vector<int>> initialBoard = {
            {1,  -1, -1, 2},
            {3,  -1, -1, 4},
            {5,  6,  7,  8},
            {5,  9, 10, 8},
            {11, 0,  0,  12}
    };

    pair<int, int> empty1(4, 1); // coordinates of initial empty space
    pair<int, int> empty2(4, 2); // coordinates of the other initial empty space

    State initialState(initialBoard, empty1, empty2);

    //
     //Node root(initialState, nullptr, 0, 0);
    //Search search = Search();


    Node * root = new Node(initialState, nullptr, 0, 0);
    Search search = Search();
    search.addToQueue(root);
    auto start = chrono::high_resolution_clock::now();
    search.search();
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<std::chrono::minutes>(stop -start);

    cout << endl << "The algorithm had ran for " << duration.count() << endl;
    // astar a(initialState);
    // a.solve();

    dfs.solve();

    //astar a(root);
    //a.solve();
    //search.addToQueue(root);
    //search.search();
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
