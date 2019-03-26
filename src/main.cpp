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



vector<vector<vector<int>>> piecesToMove(vector<vector<int>> state, pair<int,int> empty1, pair<int,int> empty2){

vector<pair<int,int>> adjacentPieces = getAdjacent(state, empty1, empty2);
}

int main() {
    vector<vector<int>> initialState = {
        {1, -1, -1, 2},
        {3, -1, -1, 4},
        {5, 6, 7, 8},
        {5, 9, 10, 8},
        {11, 0, 0, 12}
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
