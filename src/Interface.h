//
// Created by daniel on 02-04-2019.
//

#ifndef FEUP_IART_INTERFACE_H
#define FEUP_IART_INTERFACE_H


#include <string>

class Interface {

private:
    int dificultyL;
    int algorithm;
    bool getout = false;

public:

    Interface();
    void getInput();
    void  dificulty();
    void alg();
    bool out();
    void setOut();
};


#endif //FEUP_IART_INTERFACE_H
