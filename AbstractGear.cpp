#include "AbstractGear.hpp"

using namespace std;

AbstractGear::AbstractGear(int* config, string input) {
	_config = config;
	_input = input;
	_inputLength = sizeof(_input)/sizeof(char);
}

