#include "Plugboard.hpp"

  Plugboard::Plugboard(std::vector<int> config):AbstractGear(config) {
    _config = config;
  }

  int Plugboard::map(int input) {
    
      for(int i = 0; i < (int)_config.size(); i++) {
	
	if(_config[i] == input) {
	  
	  if(i%2 == 0) {
	    /* get the right one if i is even. */
	    return _config[i+1];
	  } else {
	    /* get the left one if i is odd. */
	    return _config[i-1];
	  }
	} 
      }
      return input;
  }
  
