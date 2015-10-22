#include <string>
#include "RotorReflector.hpp"
#include "PlugBoard.hpp"

class EnigmaMachine {
    public:
        EnigmaMachine(int, char**);
    private:
        int _argc;
        char** _argv;
        std::unique_ptr<PlugBoard> plugboard;
        std::unique_ptr<RotorReflector> rotorReflector;
        std::string decrypt(std::string);
}
