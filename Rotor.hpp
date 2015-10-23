#ifndef ROTOR_H
#define ROTOR_H

#include "AbstractGear.hpp"

class Rotor:public AbstractGear {
	public:
		Rotor(int*);
		int map(int);
	private:
		int rotateCounter;
		void rotate();
		bool rotateNext;
};

#endif
