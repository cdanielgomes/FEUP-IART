#ifndef STATE_H
#define STATE_H

#include <vector>
#include <utility>
#include <iomanip>
#include <iostream>
#include <unordered_map>

class State {
 private:
  /* 0 - empty square (1x1)
    -1 - 2x2 block
    1 - 1x1 block
    2 - 1x2 block
    3 - 2x1 block */
    enum blockType {red = -1, empty = 0, square = 1, doubleVertical = 2, doubleHorizontal = 3};
    enum direction {up = 0, right = 1, down = 2, left = 3};

    std::vector<std::vector<int>> board;
    std::pair<int, int> empty1;
    std::pair<int, int> empty2;

public:
    State(std::vector<std::vector<int>> board, std::pair<int, int> empty1, std::pair<int, int> empty2);
    void printState();
    std::vector<std::pair<std::pair<int,int>, int>> getAdjacents();
    std::vector<State> getChildren();
    State moveBlock(std::pair<int,int> block, int direction);
    int getElement(int x, int y);
};

#endif /* STATE_H */