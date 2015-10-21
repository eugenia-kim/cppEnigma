#include "PlugBoard.hpp"

PlugBoard::PlugBoard(int* config, char* input):AbstractGear(config, input) {
	_config = config;
	_input = input;
}

char* PlugBoard::map(void) {
	return _input;
}