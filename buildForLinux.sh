#!/bin/bash

g++ -std=c++11 -c ./src/Random.cpp ./src/linuxMain.cpp ./src/logChecker.cpp
g++ -o SeedGenerator Random.o logChecker.o linuxMain.o -static-libgcc -static-libstdc++ 
rm Random.o logChecker.o linuxMain.o
