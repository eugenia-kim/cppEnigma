#include <list>
#include <memory>
#include "PlugBoard.hpp"
#include "Rotor.hpp"

class EnigmaMachine {
    public:
        EnigmaMachine();
        EnigmaMachine(std::list<Rotor>, PlugBoard&);
        void decrypt();
    private:
        PlugBoard* _plugboard;
        list<Rotor> _rotors;
};
