#ifndef MACHINE_H
#define MACHINE_H

#include <vector>
#include <memory>
#include <fstream>

#include "Plugboard.hpp"
#include "Rotor.hpp"

class Machine {
public:
	Machine(std::vector<char*>, char*);
	void decrypt();
	int exit;
private:
	int numRotors;
	std::unique_ptr<Plugboard> pb;
	std::vector<std::unique_ptr<Rotor>> rotors;
	std::vector<int> setConfigPB(char*);
	std::vector<std::vector<int>> setConfigRotors(std::vector<char*> rotorFile);
	bool isUpper(char);
};

#endif