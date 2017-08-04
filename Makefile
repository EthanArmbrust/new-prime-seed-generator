CXX = g++
CXXFLAGS = -c -std=c++11 -O3 
LDFLAGS = -static-libgcc -static-libstdc++ -pthread
SOURCES = ./src/main.cpp ./src/Random.cpp ./src/logChecker.cpp ./src/BigInteger/BigUnsigned.cc ./src/BigInteger/BigUnsignedInABase.cc ./src/BigInteger/BigIntegerUtils.cc ./src/BigInteger/BigInteger.cc
OBJECTS= $(SOURCES:.cpp=.o)
EXECUTABLE=bin/SeedGeneratorLinux

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@ 
clean:
	rm ./src/*.o $(EXECUTABLE)
