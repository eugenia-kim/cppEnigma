#include "Rotor.hpp"

Rotor::Rotor(int* config, string input, int ith) {
	_config = config;
	_input = input;
	_ith = ith;
}

char* Rotor::map() {
	char*& inputRef = _input;
	int rotateIndex = pow(26, _ith);
	for(int i = 0; i<_inputlength; i++) {
		if(i%rotateIndex == 0) {
			rotate();
		}
		char token = charToDec(intputRef[i]);
		inputRef[i] = (char)(retrieveNextSeq(token));
	}
}

void Rotor::rotate() {
	char*& inputRef = _input;
	for(int i = 0; i<_inputlength; i++) {
		inputRef[i] = (char)((int)inputRef[i] + 1);
	}
}

int Rotor::retrieveNextSeq(int input) {
	int index;
	for(int i = 0; i < 26; i++) {
		if(_config[i] == input) {
			index = i;
			break;
		}
	}
	return (index + 1)%26;
}