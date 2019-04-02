//
// Created by daniel on 02-04-2019.
//

#include "Interface.h"
#include <iostream>
#include "search.h"
#include "DFS.h"
#include "common.h"
#include "astar.h"
#include "chrono"

using namespace std;

vector<vector<vector<int>>> board = {
        {
                {1, -1, -1, 2},
                {3, -1, -1, 5},
                {3, 6, 7, 8},
                {4, 9, 10, 11},
                {4, 0, 0, 11}
        },
        {
                {1, -1, -1, 2},
                {1, -1, -1, 3},
                {4, 4, 5, 5},
                {6, 6, 7,  7},
                {8, 0, 0, 9}
        }

};


pair<int, int> empty1(4, 1); // coordinates of initial empty space
pair<int, int> empty2(4, 2); // coordinates of the other initial empty space



Interface::Interface() {}


void Interface::dificulty() {

    cout << "1 - Level easy\n"
            "2 - Level medium\n"
            "3 - Level hard \n"
            "4 - exit\n";


    cin >> dificultyL;

    switch (dificultyL) {
        case 1:
            alg();
            break;
        case 2:
            alg();
            break;
        case 3:

            alg();
            break;
        default:
            setOut();
            return;
    }
}

void lmao(Node *n) {

    auto start = std::chrono::high_resolution_clock::now();

    Search i = Search();
    i.addToQueue(n);
    i.search();

    auto end = std::chrono::high_resolution_clock::now();

    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    cout << "DURATION: " << time << "ms\n\n";
}

void lmao2(Node *n) {

    auto start = std::chrono::high_resolution_clock::now();

    DFS s = DFS(n, 40);
    s.solve();

    auto end = std::chrono::high_resolution_clock::now();

    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    cout << "DURATION: " << time << "ms\n\n\n";

}

void lmao3(Node *n) {

    auto start = std::chrono::high_resolution_clock::now();

    astar a(n);
    a.solveAStar();

    auto end = std::chrono::high_resolution_clock::now();

    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    cout << "DURATION: " << time << "ms\n\n\n";

}

void lmao4(Node *n) {
    auto start = std::chrono::high_resolution_clock::now();

    astar b(n);
    b.solveAStar();
    auto end = std::chrono::high_resolution_clock::now();

    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    cout << "DURATION: " << time << "ms\n\n\n";

}

bool Interface::out() {
    return getout;
}

void Interface::setOut() {
    this->getout = true;
}


void Interface::alg() {
    cout << "1- BFS\n"
            "2- DFS (iterative) \n"
            "3- A*\n"
            "4- Greedy\n"
            "5- back\n";

    State initialState(board[dificultyL], empty1, empty2);

    Node *n = new Node(initialState, nullptr, 0, 0);

    cin >> this->algorithm;

    switch (this->algorithm) {
        case 1:
            lmao(n);
            break;
        case 2:
            lmao2(n);
            break;
        case 3:
            lmao3(n);
            break;
        case 4:
            lmao4(n);
            break;
        default:
            return;

    }
}

