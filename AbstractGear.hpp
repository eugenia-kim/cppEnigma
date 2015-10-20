#ifndef ABSTRACTGEAR_H
#define ABSTRACTGEAR_H

#include<iostream>

class AbstractGear {
    public:
    	AbstractGear(int*, string);
        virtual char* map(void) = 0;
        virtual int upperCharToDec(char alphabet) =  (int)alphabet - 65;
        virtual int lowerCharToDec(char alphabet) = (int)alphabet - 97;

    protected:
    	int* _sequence;
    	char* _input;
};

class Rotor:public AbstractGear {
	public:
		Rotor(int*, string, int);
		char* map(void);
		int _ith;
	private:
		void rotate(void);
		int retrieveNextSeq(int);
};

class PlugBoard:public AbstractGear {
	public:
		PlugBoard(int*, string);
		char* map(void);
};

#endif
