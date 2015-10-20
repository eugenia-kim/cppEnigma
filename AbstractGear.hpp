#ifndef ABSTRACTGEAR_H
#define ABSTRACTGEAR_H

#include<iostream>
#include <fstream>

class AbstractGear {
    public:
    	AbstractGear(ifstream, string);
        virtual char* map(void) = 0;
        virtual int charToDec(char alphabet) =  (int)alphabet - 65;

    protected:
    	ifstream _config;
    	char* _input;
    	int _inputLength;
};

#endif