#ifndef STATE_H
#define STATE_H

#include "block.h"
#include <vector>
#include <utility>
#include <iomanip>
#include <iostream>
#include <unordered_map>

class State {
 private:

    enum blockType {empty = 0, square = 1, rectangle = 2, red = 4};
    enum direction {up = 0, right = 1, down = 2, left = 3};

    std::vector<std::vector<int>> board;
    std::pair<int, int> empty1;
    std::pair<int, int> empty2;
    std::unordered_map<int, Block> blocks;


public:
    State(std::vector<std::vector<int>> board, std::pair<int, int> empty1, std::pair<int, int> empty2);
    State(std::vector<std::vector<int>> board);
    void printState();
    std::vector<std::pair<std::pair<int,int>, int>> getAdjacents();
    std::vector<State> getChildren();
    State moveBlock(std::pair<int,int> block, int direction);
    int getElement(int x, int y);
    bool validMove(Block block);
    std::vector<std::vector<int>> updateBoard();
};

#endif /* STATE_H */