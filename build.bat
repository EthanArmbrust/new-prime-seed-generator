g++ -c --std=c++11 .\src\main.cpp .\src\logChecker.cpp .\src\Random.cpp .\src\BigInteger\BigUnsigned.cc .\src\BigInteger\BigUnsignedInABase.cc .\src\BigInteger\BigIntegerUtils.cc .\src\BigInteger\BigInteger.cc
cd src
windres sgIcon.rc -O coff -o icon.res
cd ..
g++ -o SeedGenerator.exe Random.o logChecker.o main.o BigUnsigned.o BigIntegerUtils.o BigUnsignedInABase.o BigInteger.o .\src\icon.res -static-libgcc -static-libstdc++
del Random.o logChecker.o main.o BigUnsigned.o BigIntegerUtils.o BigUnsignedInABase.o BigInteger.o
