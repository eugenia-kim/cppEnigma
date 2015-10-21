#ifndef ABSTRACTGEAR_H
#define ABSTRACTGEAR_H

#include <iostream>
#include <fstream>

using namespace std;

class AbstractGear {
    public:
    	AbstractGear(int*, string);
        virtual char* map(void) = 0;
        virtual int charToDec(char alphabet);


    protected:
    	int* _config;
    	char* _input;
    	int _inputLength;
};

#endif