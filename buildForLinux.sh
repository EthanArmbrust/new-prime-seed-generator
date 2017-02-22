#!/bin/bash

g++ -std=c++11  -c ./src/Random.cpp ./src/linuxMain.cpp ./src/logChecker.cpp -O3
g++ -o SeedGeneratorLinux Random.o logChecker.o linuxMain.o -static-libgcc -static-libstdc++ -pthread
rm Random.o logChecker.o linuxMain.o
