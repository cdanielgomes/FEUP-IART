#include "block.h"

using namespace std;

Block::Block(int index) {
    this->index = index;
}

void Block::addPos(int x, int y){
    this->brothers.push_back(pair<int,int>(x,y));
}

vector<pair<int,int>> Block::getBros() {
    return this->brothers;
}
void Block::setBros(vector<pair<int,int>> bros) {
    this->brothers = bros;
}


void Block::setPos(int x, int y) {
    for(auto i:this->brothers) {
        i.first += x;
        i.second += y;
    }
}