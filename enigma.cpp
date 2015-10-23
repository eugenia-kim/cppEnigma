// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <vector>
#include <fstream>
#include <memory>

#include "Machine.hpp"
#include "AbstractGear.hpp"

int main(int argc, char **argv) {

    if(argc < 1) {
        //error
    }
    
    char* pbFileName;
    for(int i = 0; i < argc; i++) {
      if(std::string(argv[i]).find(".pb")) {
	pbFileName = argv[i];
      } else {
	//throw error
      }
    }
  
    std::unique_ptr<Machine> enigma (new Machine(pbFileName));
    enigma->decrypt();
    return 0;
}
