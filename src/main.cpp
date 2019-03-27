#include "search.h"

using namespace std;

int main() {

    vector<vector<int>> initialBoard = {
            {1, 4, 4, 2},
            {3, 4, 4, 4},
            {5, 6, 7, 8},
            {5, 9, 10, 8},
            {11, 0, 0, 12}
    };

    pair<int,int> empty1(4, 1); // coordinates of initial empty space
    pair<int,int> empty2(4, 2); // coordinates of the other initial empty space

    State initialState(initialBoard, empty1, empty2);
    initialState.printState();
  /*  Node root(initialState, nullptr, 0, 0);
    Search search = Search();

    search.addToQueue(root);
    search.search();
*/
}
