#include "state.h"

using namespace std;

/*State::State(std::vector<std::vector<int>> board, std::pair<int, int> empty1, std::pair<int, int> empty2)
    : board(board), empty1(empty1), empty2(empty2) {}
*/

State::State(std::vector<std::vector<int>> board, std::pair<int, int> empty1, std::pair<int, int> empty2) {

    int x = 0;
    int y = 0;
    this->empty1 = empty1;
    this->empty2 = empty2;

    for (auto &i : board) {
        for (auto &j: i) {

                try {
                    Block &block = this->blocks.at(j);
                    block.addPos(x, y);
                } catch (const std::out_of_range &oor) {
                    Block block(j);
                    block.addPos(x, y);
                    this->blocks.insert(std::pair<int, Block>(j, block));
                }

            x++;
        }
        x = 0;
        y++;
    }
}


void State::printState() {

/*    for (auto line = this->board.begin(); line != this->board.end(); line++) {
        for (auto column = (*line).begin(); column != (*line).end(); column++) {
            switch (*column) {
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

*/
    std::vector<std::vector<int>> lmao(5, vector<int>(4,1)) ;

    for (auto i : this->blocks) {
        for (auto j : i.second.getBros()) {
            lmao[j.second][j.first] = i.first;
        }
    }

    for (auto &i : lmao) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

vector<pair<pair<int, int>, int>> State::getAdjacents() {
    pair<int, int> empty = this->empty1;
    vector<pair<pair<int, int>, int>> pieces;

    for (int i = 0; i < 2; i++) { // 2 empty blocks
        if (empty.first < 4) {
            pieces.push_back(pair<pair<int, int>, int>(pair<int, int>(empty.first + 1, empty.second), up));
        }

        if (empty.first > 0) {
            pieces.push_back(pair<pair<int, int>, int>(pair<int, int>(empty.first - 1, empty.second), down));
        }

        if (empty.second < 3) {
            pieces.push_back(pair<pair<int, int>, int>(pair<int, int>(empty.first, empty.second + 1), left));
        }

        if (empty.second > 0) {
            pieces.push_back(pair<pair<int, int>, int>(pair<int, int>(empty.first, empty.second - 1), right));
        }

        empty = this->empty2;
    }

    return pieces;
}

State State::moveBlock(pair<int, int> block, int direction) {
    int x = block.first, y = block.second;
    vector<vector<int>> newBoard = this->board;

    int element = getElement(x, y);
    int shift = 0;
    if (element != square) {
        shift = 1;
    }

    switch (direction) {
        case up:
            newBoard[x][y] = element;
            newBoard[x - 1][y] = element;
            newBoard[x + shift][y] = empty;
            break;

        case down:
            newBoard[x][y] = element;
            newBoard[x - shift][y] = empty;
            newBoard[x + 1][y] = element;
            break;

        case right:
            newBoard[x][y] = element;
            newBoard[x][y + 1] = element;
            newBoard[x][y - shift] = empty;
            break;

        case left:
            newBoard[x][y] = element;
            newBoard[x][y - 1] = element;
            newBoard[x][y + shift] = empty;
            break;
    }

    State newState(newBoard, pair<int, int>(0, 0), pair<int, int>(0, 0));
    return newState;
}

vector<State> State::getChildren() {
    vector<State> children;
    vector<pair<pair<int, int>, int>> adjacents = getAdjacents();

    // erase empty spaces from adjacent blocks
    for (auto it = adjacents.begin(); it != adjacents.end(); it++) {
        pair<int, int> block = (*it).first;
        int element = getElement(block.first, block.second);
        if (element == empty) { // empty space
            adjacents.erase(it);
            it--;
            continue;
        }
        cout << getElement((*it).first.first, (*it).first.second) << endl;
    }

    // cout << "x: " << adjacents[0].first.first << 
    //     " y: " << adjacents[0].first.second << 
    //     " direction: " << adjacents[0].second << endl; 

    // moveBlock(adjacents[0].first, adjacents[0].second).printState();

    return children;
}

int State::getElement(int x, int y) {
    return this->board[x][y];
}