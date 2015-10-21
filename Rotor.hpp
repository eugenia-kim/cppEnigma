#ifndef ROTOR_H
#define ROTOR_H

#include <cmath>
#include "AbstractGear.hpp"

class Rotor:public AbstractGear {
	public:
		Rotor(int*, string, int);
		char* map(void);
		int _ith;
	private:
		void rotate(void);
		int retrieveNextSeq(int);
};

#endif