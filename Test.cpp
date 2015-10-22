#include <cassert>
#include <string.h>
#include <iostream>
#include "AbstractGear.hpp" 
#include "Rotor.hpp"
#include "PlugBoard.hpp"

using namespace std;

void RotateMapTest() {
	int* config = new int[26];
	for(int i = 0; i < 26; i++) {
		config[i] = i;
	}
	string input = "ABCD";
	Rotor rotor(config);
	for(int i = 0; i < (int)input.size(); i++) {
		cout<< input[i] << endl;
		cout << rotor.map(input[i]) << endl;
	}
	//assert(strcmp(result, "IGOP") == 0);
}

int main() {
	RotateMapTest();
	return 0;
}
