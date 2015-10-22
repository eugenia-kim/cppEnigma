#include "Rotor.hpp"

using namespace std;

Rotor::Rotor(int* config):AbstractGear(config) {
	_config = config;
	rotateCounter = 0;
	rotateNext = false;
}

// char* Rotor::map() {
// 	char*& inputRef = _input;
// 	int rotateIndex = pow(26, _ith);
// 	//cout << _input << endl;
// 	//cout << (sizeof(_input))/(sizeof(char)) << endl;
// 	for(int i = 0; i<_inputLength; i++) {
// 		if(i%rotateIndex == 0) {
// 			rotate();
// 		}
// 		int token = charToDec(inputRef[i]);
// 		inputRef[i] = retrieveNextSeq(token);
// 	}
// 	return inputRef;
// }

void Rotor::rotate() {
	rotateCounter = rotateCounter + 1;
	if(rotateCounter == 26) {
		rotateNext = true;
		rotateCounter = 0;
	}
}

// void Rotor::rotate() {
// 	char*& inputRef = _input;
// 	for(int i = 0; i<_inputLength; i++) {
// 		inputRef[i] = (char)((int)inputRef[i] + 1);
// 	}
// }

char Rotor::map(char letter) {
	int inputNum = charToDec(letter);
	inputNum += rotateFreq; 
	int index;
	for(int i = 0; i < 26; i++) {
		if(_config[i] == inputNum) {
			index = i;
			break;
		}
	}
	rotateFreq++;
	return intToChar((index + 1)%26);
}
