#include "search.h"
//#include "DFS.h"
#include "astar.h"
#include "node.h"
#include "Interface.h"
#include <chrono>

using namespace std;

int main() {

    Interface * k = new Interface();


    while(!k->out()){

        k->dificulty();
    }

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
