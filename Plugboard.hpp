#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "AbstractGear.hpp"

class Plugboard:public AbstractGear {
    public:
	Plugboard(int*);
        int map(int);
	int countArray(int*);
};

#endif