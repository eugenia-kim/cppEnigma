#include "Rotor.hpp"

using namespace std;

Rotor::Rotor(vector<int> config):AbstractGear(config) {
  
  _config = config;
  counter = 0;
  rotateNext = false;
}

int Rotor::map(int num) {
  
  int input = (num + counter)%ALPHA;
  int output = _config[input];
  
  return (output - counter + ALPHA)%ALPHA;
}

int Rotor::reverseMap(int num) {
  
  int input = (num + counter)%ALPHA;
  int output;
  
  for(int i = 0; i < ALPHA; i++) {
    
    if(_config[i] == input) {
     
      output = i;
      break;
    }
  }
  
  return (output - counter + ALPHA)%ALPHA;
}

void Rotor::rotate() {
  
  counter++;
  
  /* set the next rotor to rotate if the current one reaches 26 counters. */
  if(counter == ALPHA) {
    
    rotateNext = true;
    counter = 0;
  } else {
    
    rotateNext = false;
  }
}
  
