#ifndef ABSTRACTGEAR_H
#define ABSTRACTGEAR_H

#include <iostream>
#include <fstream>

using namespace std;

class AbstractGear {
    public:
    	AbstractGear(int* config);
        virtual char map(char) = 0;
        virtual int charToDec(char letter);
        virtual char intToChar(int number);


    protected:
    	int* _config;
    	char _input;
};

#endif
