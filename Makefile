CXX = g++
CXXFLAGS = -c -std=c++11 -O3 
LDFLAGS = -static-libgcc -static-libstdc++
ifeq ($(CXX),i686-w64-mingw32-g++-posix)
	LDFLAGS += -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LDFLAGS += -pthread
		EXECUTABLE := bin/SeedGeneratorLinux
	endif
	ifeq ($(UNAME_S),Darwin)
		CXX := clang++
		CXXFLAGS += -stdlib=libc++
		LDFLAGS :=
		EXECUTABLE := bin/SeedGeneratorMac
	endif
endif
SOURCES = ./src/main.cpp ./src/Random.cpp ./src/logChecker.cpp ./src/BigInteger/BigUnsigned.cc ./src/BigInteger/BigUnsignedInABase.cc ./src/BigInteger/BigIntegerUtils.cc ./src/BigInteger/BigInteger.cc
OBJECTS= $(SOURCES:.cpp=.o)
ifeq ($(CXX),i686-w64-mingw32-g++-posix)
	EXECUTABLE := bin/SeedGenerator.exe
endif

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@ 
clean:
	rm ./src/*.o $(EXECUTABLE)
