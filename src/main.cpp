#include <iostream>
#include <utility>
#include "node.h"

using namespace std;

vector<pair<int,int>> getAdjacent(vector<vector<int>> state, pair<int,int> empty1, pair<int,int> empty2) {
    vector<pair<int,int>> pieces;

    if(empty1.first < 4) {
        pieces.push_back(pair<int,int>(empty1.first+1, empty1.second));
    }

    if(empty1.first > 0) {
        pieces.push_back(pair<int,int>(empty1.first-1, empty1.second));
    }

    if(empty1.second < 3) {
        pieces.push_back(pair<int,int>(empty1.first, empty1.second + 1));
    }

    if(empty1.second > 0) {
        pieces.push_back(pair<int,int>(empty1.first, empty1.second - 1));
    }

    return pieces;
}

int main() {
    /*
    0 - empty square (1x1)
    -1 - 2x2 block
    1 - 1x1 block
    2 - 1x2 block
    3 - 2x1 block
    */
    vector<vector<int>> initialState = {
        {1, -1, -1, 1},
        {1, -1, -1, 1},
        {2, 1, 1, 2},
        {2, 1, 1, 2},
        {1, 0, 0, 1}
    };

    pair<int,int> empty1(4, 1); // coordinates of initial empty space
    pair<int,int> empty2(4, 2); // coordinates of the other initial empty space

    Node root(initialState, nullptr, 0, 0);
    root.setEmpties(empty1, empty2);

    vector<pair<int,int>> adjacentPieces = getAdjacent(initialState, empty1, empty2);

    for(auto it=adjacentPieces.begin(); it!=adjacentPieces.end(); it++) {
        cout << initialState[(*it).first][(*it).second] << endl;
    }

    root.printState();

}
