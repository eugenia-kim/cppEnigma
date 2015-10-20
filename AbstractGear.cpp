#include "AbstractGear.hpp"

using namespace std;

AbstractGear::AbstractGear(int* sequence, string input) {
	_sequence = sequence;
	_input = input;
}

Rotor::Rotor(int* sequence, string input, int ith) {
	_sequence = sequence;
	_input = input;
	_ith = ith;
}

char* Rotor::map() {
	char*& inputRef = _input;
	int length = sizeof(inputRef)/sizeof(char);

	char*& sequenceRef = _sequence;
	for(int i = 0; i<length; i++) {
		
	}
}

void Rotor::rotate() {
	char*& inputRef = _input;
	int length = sizeof(inputRef)/sizeof(char);
	for(int i = 0; i<length; i++) {
		inputRef[i] = (char)((int)inputRef[i] + 1);
	}
}

int Rotor::retrieveNextSeq(int input) {

}

PlugBoard::PlugBoard(int* sequence, string input) {
	_sequence = sequence;
	_input = input;
}