#!/bin/bash

rm prog 
rm *.o
rm *.gch

g++ -g -c Assignment8.cpp Edge.h Graph.h 
g++ -g -o prog Assignment8.o
gdb prog
