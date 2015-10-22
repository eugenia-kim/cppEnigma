#ifndef ABSTRACTGEAR_H
#define ABSTRACTGEAR_H

#include <iostream>
#include <fstream>

using namespace std;

class AbstractGear {
    public:
    	AbstractGear(int* config, char* input);
        virtual char* map() = 0;
        virtual int charToDec(char letter);


    protected:
    	int* _config;
    	char* _input;
    	int _inputLength;
};

#endif
