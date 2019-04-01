#ifndef STATE_H
#define STATE_H

#include "block.h"
#include <utility>
#include <iomanip>
#include <unordered_map>

class State {
 private:

    enum blockType {empty = 0, square = 1, rectangle = 2, red = -1};
    enum direction {up = 0, right = 1, down = 2, left = 3};

    std::vector<std::vector<int>> board;
    std::pair<int, int> empty1;
    std::pair<int, int> empty2;
    std::unordered_map<int, Block> blocks;


public:
    State();
    State(std::vector<std::vector<int>> board, std::pair<int, int> empty1, std::pair<int, int> empty2);
    State(std::vector<std::vector<int>> board);
    void printState();
    std::vector<std::pair<std::pair<int,int>, int>> getAdjacents();
    std::vector<State> getChildren();
    bool moveBlock(std::pair<int,int> block, int direction, State &newState);
    Block getBlock(int i);
    int getElement(int x, int y);
    bool validMove(Block block);
    void calculateBoard();
    void calculateEmpties();
    void setBoard(std::vector<std::vector<int>> board);
    void setBlocks(std::unordered_map<int, Block> blocks);
    bool endState();
    std::vector<std::vector<int>> getBoard();
    std::vector<std::pair<int,int>> getEmpties();
};

#endif /* STATE_H */