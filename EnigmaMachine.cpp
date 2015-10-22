#include "EnigmaMachine.hpp"

EnigmaMachine::EnigmaMachine(int argc, char** argv) {
    _argc = argc;
    _argv = argv;
    plugboard = make_unique(argv[argc-1]);
    rotorReflector = make_unique(argc, argv);
   //plugboard = std::unique_ptr<Plugboard>(new Plugboard());
}

std::string EnigmaMachine::decrpyt(std::string input) {
    string decodedByPB = plugboard->map(input);
    string decodedByRR = rotorReflector->map(decodedByPB);
    string decodedStr = plugboard->map(decodedByRR);
}
