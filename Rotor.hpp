#ifndef ROTOR_H
#define ROTOR_H

#include "AbstractGear.hpp"

class Rotor:public AbstractGear {
  public:
    Rotor(std::vector<int>);
    int map(int);
    int reverseMap(int);
    void rotate();
    int counter;
    bool rotateNext;
};

#endif