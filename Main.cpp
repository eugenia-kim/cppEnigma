// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>


#include <iostream>
#include <fstream>

#include "Rotor.hpp"

int* setConfig(char* fileName);

using namespace std;

int main(int argc, char **argv)
{
	int numberOfRoters = argc - 2;
	Rotor** rotorArray = new Rotor*[numberOfRoters];
	for(int i = 0; i < numberOfRoters; i++) {
		rotorArray[i] = new Rotor(setConfig(argv[i+1]));
	}
	char input;

	while(cin >> input) {
		for(int i = 0; i < numberOfRoters; i++) {
			input = rotorArray[0]->map(input);
		}
/*		input = reflector.map(input);
		for(int i = 2; i >= 0; i--) {
			input = rotorArray[0].map(input);
		}
*/
		// for(int = 0; i < numberOfRoters; i++) {

		// }

	}
	return 0;
}

int* setConfig(char* fileName) {
	ifstream config(fileName);
	int* configuration = new int[26];
	int elem;
	int i = 0;
	while(config >> elem) {
		configuration[i] = elem;
		i++;
	}
	return configuration;
}
