//
// Created by daniel on 27-03-2019.
//

#ifndef FEUP_IART_BLOCK_H
#define FEUP_IART_BLOCK_H


#include <vector>

class Block {
private:

    std::vector<std::pair<int, int>> brothers;
    int index;
public:

Block(int index);
void addPos(int x, int y);
std::vector<std::pair<int,int>> getBros();

};


#endif //FEUP_IART_BLOCK_H
