#!/bin/bash

i686-w64-mingw32-g++ -std=c++11 -c ./src/Random.cpp ./src/windowsMain.cpp  ./src/logChecker.cpp -O3
cd src
i686-w64-mingw32-windres sgIcon.rc -O coff -o icon.res
cd ..
i686-w64-mingw32-g++ -o SeedGenerator.exe Random.o logChecker.o windowsMain.o ./src/icon.res -static-libgcc -static-libstdc++ 
rm Random.o logChecker.o windowsMain.o
