#include "PlugBoard.hpp"

PlugBoard::PlugBoard(int* config):AbstractGear(config) {
	_config = config;
}

int PlugBoard::map(int letter) {
	return 0;
}
