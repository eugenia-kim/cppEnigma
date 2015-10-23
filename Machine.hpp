#include <list>
#include <memory>
#include <fstream>

#include "Plugboard.hpp"

class Machine {
  public:
    Machine(char*);
    void decrypt();
  private:
    std::unique_ptr<Plugboard> pb;
    int* setConfig(char*);
};
