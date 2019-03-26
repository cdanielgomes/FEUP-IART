#ifndef STATE_H
#define STATE_H

#include <vector>
#include <utility>
#include <iomanip>
#include <iostream>

class State {
 private:
    std::vector<std::vector<int>> board;
    std::pair<int, int> empty1;
    std::pair<int, int> empty2;

public:
    State(std::vector<std::vector<int>> board, std::pair<int, int> empty1, std::pair<int, int> empty2);
    void printState();
    std::vector<std::pair<int,int>> getAdjacent(std::pair<int, int> empty);

};

#endif /* STATE_H */