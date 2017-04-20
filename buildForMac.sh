#!/bin/bash

g++ -std=c++11 -stdlib=libc++ -c ./src/Random.cpp ./src/main.cpp ./src/logChecker.cpp -O3
g++ -o SeedGeneratorMac Random.o logChecker.o main.o  -static-libstdc++ -pthread
rm Random.o logChecker.o main.o
