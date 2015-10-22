#include <cassert>
#include <string.h>
#include "AbstractGear.hpp" 
#include "Rotor.hpp"
#include "PlugBoard.hpp"

void RotateMapTest() {
	int* config = new int[26];
	for(int i = 0; i < 26; i++) {
		config[i] = i;
	}
	char input[] = "HELL";
	/*input[0] = 'H';
	input[1] = 'E';
	input[2] = 'L';
	input[3] = 'L';*/
	Rotor rotor(config, input, 0);
	char* result = rotor.map();
	assert(strcmp(result, "IGOP") == 0);
}

int main() {
	RotateMapTest();
	return 0;
}
