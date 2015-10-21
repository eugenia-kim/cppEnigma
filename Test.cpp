#include <cassert>
#include "AbstractGear.hpp" 
#include "Rotor.hpp"
#include "PlugBoard.hpp"

void RotateMapTest() {
	int* config;
	for(int i = 0; i < 26; i++) {
		config[i] = i;
	}
	char* input;
	input[0] = 'H';
	input[1] = 'E';
	input[2] = 'L';
	input[3] = 'L';
	Rotor rotor(config, input, 0);
	char* result = rotor.map();
	assert(result == "IGOP");
}

int main() {
	RotateMapTest();
	return 0;
}