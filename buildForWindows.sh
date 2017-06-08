#!/bin/bash

i686-w64-mingw32-g++-posix -std=c++11 -c ./src/Random.cpp ./src/main.cpp  ./src/logChecker.cpp ./src/BigInteger/BigUnsigned.cc ./src/BigInteger/BigUnsignedInABase.cc ./src/BigInteger/BigIntegerUtils.cc ./src/BigInteger/BigInteger.cc -O3
cd src
i686-w64-mingw32-windres sgIcon.rc -O coff -o icon.res
cd ..
i686-w64-mingw32-g++-posix -o ./bin/SeedGenerator.exe Random.o logChecker.o main.o BigUnsigned.o BigIntegerUtils.o BigUnsignedInABase.o BigInteger.o ./src/icon.res -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
rm Random.o logChecker.o main.o BigUnsigned.o BigUnsignedInABase.o BigIntegerUtils.o BigInteger.o
