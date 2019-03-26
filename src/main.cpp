#include <iostream>
#include <utility>
#include "node.h"

using namespace std;

int main() {
    /*
    0 - empty square (1x1)
    -1 - 2x2 block
    1 - 1x1 block
    2 - 1x2 block
    3 - 2x1 block
    */
    vector<vector<int>> initialBoard = {
        {1, -1, -1, 1},
        {1, -1, -1, 1},
        {2, 1, 1, 2},
        {2, 1, 1, 2},
        {1, 0, 0, 1}
    };

    pair<int,int> empty1(4, 1); // coordinates of initial empty space
    pair<int,int> empty2(4, 2); // coordinates of the other initial empty space

    State initialState(initialBoard, empty1, empty2);
    Node root(initialState, nullptr, 0, 0);

    root.printState();

}
