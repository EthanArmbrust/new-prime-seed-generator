#!/bin/bash

i686-w64-mingw32-g++-posix -std=c++11 -c ./src/Random.cpp ./src/mainOptions.cpp  ./src/logChecker.cpp
cd src
i686-w64-mingw32-windres sgIcon.rc -O coff -o icon.res
cd ..
i686-w64-mingw32-g++-posix -o SeedGenerator.exe Random.o logChecker.o mainOptions.o ./src/icon.res -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
rm Random.o logChecker.o mainOptions.o
