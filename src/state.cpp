#include "state.h"

using namespace std;

State::State() {}

State::State(std::vector<std::vector<int>> board) : board(board) {
    int x = 0;
    int y = 0;
    int countEmpty = 0;

    for (auto &i : board) {
        for (auto &j: i) {
            if (j != 0) {
                try {
                    Block &block = this->blocks.at(j);
                    block.addPos(x, y);
                } catch (const std::out_of_range &oor) {
                    Block block(j);
                    block.addPos(x, y);
                    this->blocks.insert(std::pair<int, Block>(j, block));
                }
            } else {
                if (countEmpty == 0) {
                    this->empty1 = pair<int, int>(x, y);
                    countEmpty++;
                } else this->empty2 = pair<int, int>(x, y);
            }
            y++;
        }
        y = 0;
        x++;
    }

}

State::State(std::vector<std::vector<int>> board, std::pair<int, int> empty1, std::pair<int, int> empty2) : board(
        board) {

    int x = 0;
    int y = 0;
    this->empty1 = empty1;
    this->empty2 = empty2;

    for (auto &i : board) {
        for (auto &j: i) {
            if (j != 0) {
                try {
                    Block &block = this->blocks.at(j);
                    block.addPos(x, y);
                } catch (const std::out_of_range &oor) {
                    Block block(j);
                    block.addPos(x, y);
                    this->blocks.insert(std::pair<int, Block>(j, block));
                }
            }
            y++;
        }
        y = 0;
        x++;
    }
}

void State::printState() {
    for (auto line : this->board) {
        for (auto element : line) {

            switch (element) {
                case -1:
                    cout << setw(5) << "x" << "|";
                    break;
                case 0:
                    cout << setw(5) << " " << "|";
                    break;
                default:
                    cout << setw(5) << element << "|";
            }

        }
        cout << endl;
    }

    cout << endl;
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

bool State::validMove(Block block) {
    vector<pair<int, int>> pos = block.getBros();

    for (auto i : pos) {
        if (this->board[i.first][i.second] != 0 && this->board[i.first][i.second] != block.getIndex())
            return false;
    }

    return true;
}

bool State::moveBlock(pair<int, int> pos, int direction, State &newState) {
    int x = pos.first, y = pos.second;
    vector<vector<int>> newBoard = this->board;

    int element = getElement(x, y);
    int shift = 0;
    Block fakeBlock = this->blocks.at(element);

    switch (direction) {
        case up:
            fakeBlock.setPos(-1, 0);
            break;
        case down:
            fakeBlock.setPos(1, 0);
            break;
        case right:
            fakeBlock.setPos(0, 1);
            break;
        case left:
            fakeBlock.setPos(0, -1);
            break;
        default:
            break;
    }

    if (validMove(fakeBlock)) {
        newState.setBlocks(this->blocks);
        Block &block = newState.blocks.at(element);
        block.setBros(fakeBlock.getBros());
    } else {
        return false;
    }

    newState.calculateBoard();
    return true;
}

void State::calculateBoard() {
    this->board = std::vector<std::vector<int>>(5, vector<int>(4, 0));

    for (auto i : this->blocks) {
        for (auto j : i.second.getBros()) {
            this->board[j.first][j.second] = i.first;
        }
    }

    calculateEmpties();
}

void State::calculateEmpties() {
    int x = 0, y = 0, empty = 1;

    for (auto i : this->board) {
        for (auto element : i) {
            if (element == 0) {
                if (empty == 1) {
                    this->empty1.first = x;
                    this->empty1.second = y;

                    //cout << "empty 1 -> x: " << x << " y: " << y << endl;
                    empty++;
                } else {
                    this->empty2.first = x;
                    this->empty2.first = y;
                    //cout << "empty 2 -> x: " << x << " y: " << y << endl << endl;
                }
            }
            y++;
        }
        y = 0;
        x++;
    }
}

vector<State> State::getChildren() {
    vector<State> children;
    vector<pair<pair<int, int>, int>> adjacents = this->getAdjacents();

    // erase empty spaces from adjacent blocks
    for (auto it = adjacents.begin(); it != adjacents.end(); it++) {
        pair<int, int> block = (*it).first;
        int element = getElement(block.first, block.second);
        if (element == empty) { // empty space
            adjacents.erase(it);
            it--;
            continue;
        }
        //cout << getElement((*it).first.first, (*it).first.second) << endl;
    }

    for (auto a : adjacents) {
        State newState = State();
        if (moveBlock(a.first, a.second, newState)) {
            //newState.printState();
            children.push_back(newState);
        }
    }

    return children;
}

int State::getElement(int x, int y)  {
    return this->board[x][y];
}

void State::setBoard(std::vector<std::vector<int>> board) {
    this->board = board;
}

void State::setBlocks(std::unordered_map<int, Block> blocks) {
    this->blocks = blocks;
}

Block State::getBlock(int i) {
    auto it = this->blocks.find(i);
    return it->second;
}

bool State::endState() {
    vector<pair<int,int>> vector = {pair<int, int>(3,1),
            pair<int, int>(3,2),
            pair<int, int>(4,1),
            pair<int, int>(4,2)};

    auto i = getBlock(-1).getBros();

    return i == vector;
}

vector<std::vector<int>> State::getBoard()  {
    return this->board;
}