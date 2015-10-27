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
  fileNotFound = 0;
  vector<int> configPB = setConfigPB(pbFile);
  pb = unique_ptr<Plugboard>(new Plugboard(configPB));
  numRotors = (int)rotorFile.size();
  vector<vector<int>> rotorConfigVector = setConfigRotors(rotorFile);

  for(int i = 0; i < numRotors; i++) {
    //auto configVec = rotorConfigVector[i];
    //unique_ptr<Rotor> rotor (new Rotor(configVec));
    
    rotors.push_back(unique_ptr<Rotor>(new Rotor(rotorConfigVector[i])));
  }
}

vector<int> Machine::setConfigPB(char* fileName) {
  
  ifstream config;
  config.open(fileName);
  if(!config.good()) {
      fileNotFound = 1;
  }
  
  vector<int> configuration;
  int elem;
  while(config >> elem) {
   configuration.push_back(elem);
  }
  return configuration;
}

vector<vector<int>> Machine::setConfigRotors(vector<char*> rotorFile) {
  vector<vector<int>> rotorConfigVector;
  for(int i = 0; i < numRotors; i++) {
    
    ifstream config;
    config.open(rotorFile[i]);
    if(!config.good()) {
     fileNotFound = 1;
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
      
	if(!isUpper(input)) {
	  cerr << "Only upper cases please" << endl;
	  exit(1);
	}
	
        int num = (int)(input - 'A');
        int pb1 = pb->map(num);
	
	for(int j = 0; j < numRotors; j++) {
	  pb1 = rotors[j]->map(pb1);
	}
	
        int rf = reflector->map(pb1);
	
	for(int k = numRotors - 1; k >= 0; k--) {
	  rf = rotors[k]->reverseMap(rf);
	}
	
	char pb2 = (char)(pb->map(rf) + A);
	
	int i = 0;
	
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