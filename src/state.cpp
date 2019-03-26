#include "state.h"

using namespace std;

State::State(std::vector<std::vector<int>> board, std::pair<int, int> empty1, std::pair<int, int> empty2)
    : board(board), empty1(empty1), empty2(empty2) {}

void State::printState() {

    for(auto line=this->board.begin(); line!=this->board.end(); line++) {
        for(auto column=(*line).begin(); column!=(*line).end(); column++) {
            switch(*column) {
                case -1: 
                cout << setw(5) << "x" << "|";
                break;
                case 0:
                cout << setw(5) << " " << "|";
                break;
                default:
                cout << setw(5) << *column << "|";
            }
            
        }
        cout << endl;
    }
}

vector<pair<int,int>> State::getAdjacent(pair<int, int> empty) {
    vector<pair<int,int>> pieces;

    if(empty.first < 4) {
        pieces.push_back(pair<int,int>(empty.first+1, empty.second));
    }

    if(empty.first > 0) {
        pieces.push_back(pair<int,int>(empty.first-1, empty.second));
    }

    if(empty.second < 3) {
        pieces.push_back(pair<int,int>(empty.first, empty.second + 1));
    }

    if(empty.second > 0) {
        pieces.push_back(pair<int,int>(empty.first, empty.second - 1));
    }

    return pieces;
}

int State::getElement(int x, int y) {
    return this->board[x][y];
}