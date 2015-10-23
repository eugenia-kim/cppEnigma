// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>

#include <list>
#include <iostream>
#include <fstream>
#include <memory>

#include "Rotor.hpp"
#include "Util.hpp"
#include "EnigmaMachine.hpp"
#include "AbstractGear.hpp"

int* setConfig(char* fileName);

using namespace std;

int main(int argc, char **argv)
{
    if(argc < 1) {
    //error msg
    }
    
//	int numberOfRoters = argc - 2;
    list<Rotor> rotors;
    
    for(int j = 0; j < argc; j++) {
        if(std::string(argv[j]).find(".pb")) {
            //unique_ptr<PlugBoard> plugboard = readPBFile(/*argv[j]*/);
        } else if(std::string(argv[j]).find(".rot")) {
            /* for(int i = 0; i < numberOfRotors; i++) {
         rotors.push_back(readRotorFile(argv[j]));
    }*/
        } else {
            //throw error invalid
        }
    }
   
   // unique_ptr<EnigmaMachine> enigma = new EnigmaMachine(rotos, plugboard);  
    EnigmaMachine* enigma = new EnigmaMachine();  
    
    enigma->decrypt();
   /*	Rotor** rotorArray = new Rotor*[numberOfRoters];
	for(int i = 0; i < numberOfRoters; i++) {
		rotorArray[i] = new Rotor(setConfig(argv[i+1]));
	}
	char input;

	while(cin >> input) {
		for(int i = 0; i < numberOfRoters; i++) {
			input = rotorArray[0]->map(input);
		}
		input = reflector.map(input);
		for(int i = 2; i >= 0; i--) {
			input = rotorArray[0].map(input);
		}
		
		int i = 0;
		do {
			rotateArray[i]->rotate();
		} while (i < numberOfRotors && rotateArray[i++]->rotateNext)

		
    
	}
*/
    delete enigma;
	return 0;
}


