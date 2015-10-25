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

    if(argc < 1) {
        //error
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
    //cout<<pbFileName<< " " << rotorFileNames.size() << endl;
    unique_ptr<Machine> enigma (new Machine(rotorFileNames, pbFileName));
   
    enigma->decrypt();
    return 0;
}
