#!/bin/bash

g++ -std=c++11  -c ./src/Random.cpp ./src/main.cpp ./src/logChecker.cpp ./src/BigInteger/BigUnsigned.cc ./src/BigInteger/BigUnsignedInABase.cc ./src/BigInteger/BigIntegerUtils.cc ./src/BigInteger/BigInteger.cc -O3
g++ -o ./bin/SeedGeneratorLinux Random.o logChecker.o main.o BigUnsigned.o BigIntegerUtils.o BigUnsignedInABase.o BigInteger.o -static-libgcc -static-libstdc++ -pthread
rm Random.o logChecker.o main.o BigUnsigned.o BigUnsignedInABase.o BigIntegerUtils.o BigInteger.o
