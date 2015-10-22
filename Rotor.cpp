#include "Rotor.hpp"

using namespace std;

Rotor::Rotor(int* config):AbstractGear(config) {
	_config = config;
	rotateFreq = 0;
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

bool Rotor::shouldRotate() {
	return (rotateFreq == 26);
}

void Rotor::rotate() {
	rotateFreq = (rotateFreq + 1)%26;
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
