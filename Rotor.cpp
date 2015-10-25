#include "Rotor.hpp"

#define ALPHA 26

using namespace std;

Rotor::Rotor(vector<int> config):AbstractGear(config) {
  _config = config;
  counter = 0;
  rotateNext = false;
}

int Rotor::map(int num) {
  int input = (num + counter)%ALPHA;
  int addOrSub = _config[input] - input;
  return (num + addOrSub)%ALPHA;
}

void Rotor::rotate() {
  counter++;
  if(counter == ALPHA) {
    rotateNext = true;
    counter = 0;
  } else {
    rotateNext = false;
  }
}
  