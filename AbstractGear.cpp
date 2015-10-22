#include "AbstractGear.hpp"

using namespace std;

AbstractGear::AbstractGear(int* config, char* input) {
	_config = config;
	_input = input;
	_inputLength = sizeof(_input)/sizeof(char);
}

int AbstractGear::charToDec(char letter) {
	 return  ((int) letter) - 65;
}
