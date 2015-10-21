#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "AbstractGear.hpp"

class PlugBoard:public AbstractGear {
	public:
		PlugBoard(int*, char*);
		char* map(void);
};

#endif