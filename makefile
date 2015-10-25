# edit this makefile so that running make compiles your enigma program

CXX = g++
CC = g++
CXXFLAGS = -pedantic -Wall -Werror -std=c++11 -g

all: enigma

enigma: AbstractGear.o Plugboard.o Reflector.o Rotor.o Machine.o enigma.o
	$(CXX) -o $@ $(CXXFLAGS) $+

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

#OBJECTS = $(wildcard *.o)

clean: 
	rm -rf enigma *.o

.PHONY: clean
