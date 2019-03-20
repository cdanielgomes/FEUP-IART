#include <iostream>
#include "node.h"

using namespace std;

int main() {
    vector<vector<int>> initialState = {
        {1, -1, -1, 2},
        {3, -1, -1, 4},
        {5, 6, 7, 8},
        {5, 9, 10, 8},
        {11, 0, 0, 12}
    };

    Node root (initialState, nullptr, 0, 0);
}
