// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>


#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	int numberOfRoters = argc - 2;
	
	
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