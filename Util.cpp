#include "Util.hpp"

static int* Util::setConfig(char* fileName) {
	ifstream config(fileName);
	int* configuration = new int[ALPHA];
	int elem;
	int i = 0;
	while(config >> elem) {
		configuration[i] = elem;
		i++;
	}
	return configuration;
}
