#!/bin/bash

clang++ -std=c++11 -stdlib=libc++ -c ./src/Random.cpp ./src/main.cpp ./src/logChecker.cpp ./src/BigInteger/BigUnsigned.cc ./src/BigInteger/BigUnsignedInABase.cc ./src/BigInteger/BigIntegerUtils.cc ./src/BigInteger/BigInteger.cc -O3
clang++ -o SeedGeneratorMac Random.o logChecker.o main.o BigUnsigned.o BigIntegerUtils.o BigUnsignedInABase.o BigInteger.o 
rm Random.o logChecker.o main.o BigUnsigned.o BigIntegerUtils.o BigUnsignedInABase.o BigInteger.o
