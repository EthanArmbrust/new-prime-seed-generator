CXX = g++
CXXFLAGS = -c -std=c++11 -O3
LDFLAGS = -static-libgcc -static-libstdc++
UNAME_S := $(shell uname -s)
SOURCES = ./src/main.cpp ./src/Random.cpp ./src/logChecker.cpp ./src/BigInteger/BigUnsigned.cc ./src/BigInteger/BigUnsignedInABase.cc ./src/BigInteger/BigIntegerUtils.cc ./src/BigInteger/BigInteger.cc
OBJECTS= $(SOURCES:.cpp=.o)

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
ifeq ($(CXX),i686-w64-mingw32-g++-posix)
	EXECUTABLE := bin/SeedGenerator.exe
	SOURCES += ./src/icon.res
	LDFLAGS += -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
endif

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@
clean:
	rm ./src/*.o
