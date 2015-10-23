#include <iostream>
#include <fstream>
#include <memory>

#include "Machine.hpp"
#include "Reflector.hpp"

#define A 65
#define ALPHA 26

using namespace std;

Machine::Machine(char* pbFile) {
  int* config = setConfig(pbFile);
  pb = unique_ptr<Plugboard>(new Plugboard(config));
}

int* Machine::setConfig(char* fileName) {
  ifstream config(fileName);
  int* configuration = new int[ALPHA];
  int elem;
  int i = 0;
  while(config >> elem) {
    configuration[i] = elem;
    i++;
  }
  return configuration;
}

void Machine::decrypt() {
    unique_ptr<Reflector> reflector (new Reflector());
    char input;
    while(cin >> ws >> input) {
        int num = (int)(input - 'A');
	int pb1 = pb->map(num) + A;
        //int rf = reflector->map(pb1);
	//char pb2 = (char)(pb->map(rf) + A);
        //cout << pb2;
	cout << pb1 << endl;
	cout << (char) (pb1 + A) << endl;
    }
}
