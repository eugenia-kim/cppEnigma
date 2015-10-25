#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

#include "Machine.hpp"
#include "Reflector.hpp"

#define A 65
#define ALPHA 26

using namespace std;

Machine::Machine(vector<char*> rotorFile, char* pbFile) {
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
  ifstream config(fileName);
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
    ifstream config(rotorFile[i]);
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
        int num = (int)(input - 'A');
        int pb1 = pb->map(num);
        //char out = (char)(pb1);
	cout << "after the first pb: " << pb1 << endl;
	
	for(int j = 0; j < numRotors; j++) {
	  pb1 = rotors[j]->map(pb1);
	  cout << "after the "<< j << " rotor: " << pb1 << endl;
	}
	
        int rf = reflector->map(pb1);
	cout << "after the reflector: " << rf << endl;
	
	for(int k = 3; k < numRotors; k--) {
	  rf = rotors[k]->map(rf);
	  cout << "after the "<< k << " rotor: " << rf << endl;
	}
	
	char pb2 = (char)(pb->map(rf) + A);
	cout << "after the last pb: " << pb2 << endl;
	
	int i = 0;
	
	do {
	  rotors[i]->rotate();
	} while (i < numRotors && rotors[i++]->rotateNext);
	
        cout << pb2;
        //cout << out;
    }
}
