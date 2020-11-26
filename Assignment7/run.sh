#!/bin/bash

rm prog 
rm *.o
rm *.gch

g++ -c Assignment7.cpp LinkedList.h Graph.h MinHeap.h
g++ -o prog Assignment7.o
./prog < input2.txt