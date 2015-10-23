#include "EnigmaMachine.hpp"
#include "Reflector.hpp"

#include <iostream>

using namespace std;

EnigmaMachine::EnigmaMachine() {}

EnigmaMachine::EnigmaMachine(list<Rotor> rotors, PlugBoard& plugboard) 
  : _plugboard(&plugboard), _rotors(rotors)
{   
    //plugboard = std::unique_ptr<Plugboard>(new Plugboard());
}

void EnigmaMachine::decrypt() {
   Reflector* reflector = new Reflector();
    char input;
    while(cin >> ws >> input) {
        int num = (int)(input - 'A');
        char out = (char) (reflector->map(num) + 'A');
        std::cout << out;
    }
    //delete reflector;
}
