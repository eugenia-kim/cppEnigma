#include "AbstractGear.hpp"

using namespace std;

AbstractGear::AbstractGear(int* config) {
	_config = config;
}

int AbstractGear::charToDec(char letter) {
	 return  ((int) letter) - 65;
}

char AbstractGear::intToChar(int number) {
	 return  (char) (number + 65);
}
