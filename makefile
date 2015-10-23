# edit this makefile so that running make compiles your enigma program

CXX = g++
CC = g++
CXXFLAGS = -pedantic -Wall -Werror -std=c++11 -g 

OBJECTS = EnigmaMachine.o Reflector.o AbstractGear.o

all: enigma 
#PlugBoard.o Rotor.o Main.o enigma

enigma: enigma.cpp $(OBJECTS)


EnigmaMachine.o: EnigmaMachine.hpp

Reflector.o: AbstractGear.hpp Reflector.hpp

#Test: Test.cpp AbstractGear.o Rotor.o PlugBoard.o 

AbstractGear.o: AbstractGear.hpp

#PlugBoard.o: AbstractGear.hpp PlugBoard.hpp

#Rotor.o: AbstractGear.hpp Rotor.hpp 

clean:
	rm -rf enigma *.o

.PHONY: clean
