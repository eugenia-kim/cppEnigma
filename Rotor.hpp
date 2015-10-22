#ifndef ROTOR_H
#define ROTOR_H

#include <cmath>
#include "AbstractGear.hpp"

class Rotor:public AbstractGear {
	public:
		Rotor(int*);
		char map(char);
	private:
		int rotateCounter;
		void rotate();
		bool rotateNext;
};

#endif
