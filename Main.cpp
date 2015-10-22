// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>


#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	int numberOfRoters = argc - 2;
	//cin input
	AbstractGear* AG;
	//PB
/*	for(int i = 0; i < 3; i++) {
		char* fileName = argv[i+1];
		//*AG = Rotor(setConfig(fileName), input, i);
		//AG->map();
	}
	AG->_input;
	Reflector
	for loop again
	PB 
*/	
	return 0;
}

int* setConfig(char* fileName) {
	ifstream config(fileName);
	int* configuration;
	int elem;
	int i = 0;
	while(config >> elem) {
		configuration[i] = elem;
		i++;
	}
	return configuration;
}
