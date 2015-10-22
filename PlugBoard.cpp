#include "PlugBoard.hpp"

PlugBoard::PlugBoard(int* config):AbstractGear(config) {
	_config = config;
}

char PlugBoard::map(char letter) {
	return 'a';
}