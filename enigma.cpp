// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <vector>
#include <fstream>
#include <memory>
#include <iostream>

#include "Machine.hpp"
#include "AbstractGear.hpp"

#define MIN_NUM_ARGC 2

using namespace std;

int main(int argc, char **argv) {

	/* checking if the number of arguments are given correctly */
	if(argc < MIN_NUM_ARGC) {
		cerr << "not enough arguments" << endl;
	}

	char* pbFileName;
	vector<char*> rotorFileNames;

	/* searching for .pb and .rot files */
	for(int i = 0; i < argc; i++) {

		if(string(argv[i]).find(".pb")!= string::npos) {

			pbFileName = argv[i];
		} else if(string(argv[i]).find(".rot")!= string::npos) {

			rotorFileNames.push_back(argv[i]);
		}
	}

	unique_ptr<Machine> enigma (new Machine(rotorFileNames, pbFileName));

	/* if the file given is not found in the directory then enigma doesn't do anything */
	if(!enigma->exit) {
		enigma->decrypt();
	}

	return enigma->exit;
}
