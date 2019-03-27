//
// Created by daniel on 27-03-2019.
//

#include "Block.h"

Block::Block(int index) {
    this->index = index;
}

void Block::addPos(int x, int y){
    std::vector<std::pair<int,int>> a = this->getBros();
    a.push_back(std::pair<int, int>(x,y));
    this->brothers = a;
}

std::vector<std::pair<int,int>> Block::getBros() {
    return this->brothers;
}

