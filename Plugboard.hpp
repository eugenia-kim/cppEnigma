#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "AbstractGear.hpp"

class Plugboard:public AbstractGear {
public:
	Plugboard(std::vector<int>);
	int map(int);
};

#endif
