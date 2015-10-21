# edit this makefile so that running make compiles your enigma program

CXX = g++
CC = g++
CXXFLAGS =  -pedantic -Wall -Werror -std=c++11 -g 

enigma: Main.o
	g++ -o enigma Main.o

Main.o: Main.cpp
	g++ -c Main.cpp

Rotor.o: AbstractGear.hpp Rotor.cpp Rotor.hpp
	
PlugBoard.o: AbstractGear.hpp PlugBoard.cpp PlugBoard.hpp

clean:
	rm -rf enigma *.o

.PHONY: clean
