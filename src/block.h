#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

class Block {
private:
    std::vector<std::pair<int, int>> brothers;
    int index;

public:

    Block(int index);
    void addPos(int x, int y);
    void setPos(int x, int y);
    std::vector<std::pair<int,int>> getBros();
    void setBros(std::vector<std::pair<int,int>> bros);
};


#endif /* BLOCK_H */
