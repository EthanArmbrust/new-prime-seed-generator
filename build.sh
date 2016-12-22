#!/bin/bash

i686-w64-mingw32-g++-posix -std=c++11 -c ./src/Random.cpp ./src/mainOptions.cpp  ./src/logChecker.cpp
i686-w64-mingw32-g++-posix -o SeedGenerator.exe Random.o logChecker.o mainOptions.o -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
rm Random.o logChecker.o mainOptions.o
