# edit this makefile so that running make compiles your enigma program

CXX = g++
#CC = g++
CXXFLAGS = -pedantic -Wall -Werror -std=c++11 -g 

all: PlugBoard.o Rotor.o Main.o enigma

enigma: Main.o

Main.o: Main.cpp

Test: Test.cpp AbstractGear.o Rotor.o PlugBoard.o 

AbstractGear.o: AbstractGear.hpp

PlugBoard.o: AbstractGear.hpp PlugBoard.hpp

Rotor.o: AbstractGear.hpp Rotor.hpp 

clean:
	rm -rf enigma *.o

.PHONY: clean
