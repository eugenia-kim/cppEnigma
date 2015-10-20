#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "AbstractGear.hpp"

class PlugBoard:public AbstractGear {
	public:
		PlugBoard(int*, string);
		char* map(void);
};

#endif