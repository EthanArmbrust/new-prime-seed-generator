g++ -c --std=c++11 .\src\windowsMain.cpp .\src\logChecker.cpp .\src\Random.cpp
cd src
windres sgIcon.rc -O coff -o icon.res
cd ..
g++ -o SeedGenerator.exe Random.o logChecker.o windowsMain.o .\src\icon.res -static-libgcc -static-libstdc++
del Random.o logChecker.o windowsMain.o
