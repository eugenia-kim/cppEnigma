#include "Plugboard.hpp"
#include <iostream>
  Plugboard::Plugboard(int* config):AbstractGear(config) {
    _config = config;
  }

  int Plugboard::countArray(int* array) {
    return sizeof(array)/sizeof(array[0]);
  }
  
  int Plugboard::map(int input) {
    
      //for(int i = 0; i < 10; i++) {
	//std::cout << _config[i] <<std::endl;
      //}
      
    std::cout << countArray(_config) <<std::endl;
      for(int i = 0; i < countArray(_config); i++) {
	std::cout << "im in the loop" <<std::endl;
	if(_config[i] == input) {
	  std::cout << _config[i] <<std::endl;
	  if(i%2 == 0) {
	    return _config[i+1];
	  } else {
	    return _config[i-1];
	  }
	} 
      }
      return input;
  }
  
