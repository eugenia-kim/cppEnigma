// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <vector>
#include <fstream>
#include <memory>
#include <iostream>

#include "Machine.hpp"
#include "AbstractGear.hpp"

using namespace std;

int main(int argc, char **argv) {

    if(argc < 2) {
        cerr << "not enough arguments" << endl;
    }
    
    char* pbFileName;
    vector<char*> rotorFileNames;
    for(int i = 0; i < argc; i++) {
      if(string(argv[i]).find(".pb")!= string::npos) {
	pbFileName = argv[i];
	
      } else if(string(argv[i]).find(".rot")!= string::npos) {
	
	rotorFileNames.push_back(argv[i]);
      }
    }

    unique_ptr<Machine> enigma;
    

    enigma = unique_ptr<Machine> (new Machine(rotorFileNames, pbFileName));
     
    if(!enigma->fileNotFound) {
    enigma->decrypt();
    }
    
    return enigma->fileNotFound;
}
