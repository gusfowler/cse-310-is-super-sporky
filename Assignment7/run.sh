#!/bin/bash

rm prog 
rm *.o
rm *.gch

g++ -g -c Assignment7.cpp LinkedList.h Graph.h MinHeap.h
g++ -g -o prog Assignment7.o
gdb prog
