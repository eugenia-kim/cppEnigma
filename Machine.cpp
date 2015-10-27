#include <iostream>
#include <fstream>
#include <stdexcept>
#include <memory>
#include <vector>

#include "Machine.hpp"
#include "Reflector.hpp"

#define A 65
#define ALPHA 26

using namespace std;

Machine::Machine(vector<char*> rotorFile, char* pbFile) {

	exit = 0;
	vector<int> configPB = setConfigPB(pbFile);
	pb = unique_ptr<Plugboard>(new Plugboard(configPB));
	numRotors = (int)rotorFile.size();
	vector<vector<int>> rotorConfigVector = setConfigRotors(rotorFile);

	for(int i = 0; i < numRotors; i++) {

		rotors.push_back(unique_ptr<Rotor>(new Rotor(rotorConfigVector[i])));
	}
}

/* getting the configuration from the Plugboard file to vector. */
vector<int> Machine::setConfigPB(char* fileName) {

	ifstream config;
	config.open(fileName);

	/* checking whether the file exists. */
	if(!config.good()) {
		exit = 1;
		cerr << "the Plugboard file you entered does not exist" << endl;
	}

	vector<int> configuration;
	int elem;

	while(config >> elem) {

		configuration.push_back(elem);
	}

	return configuration;
}

/* getting the configuration from the Rotor files to vector. */
vector<vector<int>> Machine::setConfigRotors(vector<char*> rotorFile) {
	vector<vector<int>> rotorConfigVector;
	for(int i = 0; i < numRotors; i++) {

		ifstream config;
		config.open(rotorFile[i]);

		/* checking whether the file exists. */
		if(!config.good()) {
			exit = 1;
			cerr << "one of the Rotors file you entered does not exist" << endl;
		}

		vector<int> configuration;
		int elem;

		while(config >> elem) {

			configuration.push_back(elem);
		}

		rotorConfigVector.push_back(configuration);
	}

	return rotorConfigVector;
}

void Machine::decrypt() {

	unique_ptr<Reflector> reflector (new Reflector());
	char input;

	while(cin >> ws >> input) {

		/* check that inputs are only upper cases. */
		if(!isUpper(input)) {

			exit = 1;
			cerr << "Only upper cases please" << endl;
			return;
		}

		/* map the input to plugboard. */
		int num = (int)(input - 'A');
		int pb1 = pb->map(num);

		/* map the output of plugboard to rotors. */
		for(int j = 0; j < numRotors; j++) {

			pb1 = rotors[j]->map(pb1);
		}

		/* map the output from rotors to reflector. */
		int rf = reflector->map(pb1);

		/* map the output from reflector to rotors but backwards. */
		for(int k = numRotors - 1; k >= 0; k--) {

			rf = rotors[k]->reverseMap(rf);
		}

		/* map the output from rotors to plugboard. */
		char pb2 = (char)(pb->map(rf) + A);

		int i = 0;

		/* rotate the first rotor for sure and check if the next rotor should be rotated and rotate if needed. */
		do {
			if (i != numRotors) {

				rotors[i]->rotate();
			}
		} while (i < numRotors && rotors[i++]->rotateNext);


		cout << pb2;
	}
}

bool Machine::isUpper(char c) {
	return 'A' <= c && c<= 'Z';
}