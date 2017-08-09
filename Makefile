#============================================
#=============Setting defaults===============
#============================================
CXX = g++
CXXFLAGS = -c -std=c++11 -O3
LDFLAGS = -static-libgcc -static-libstdc++
UNAME_S := $(shell uname -s)
SOURCES = ./src/main.cpp ./src/Random.cpp ./src/logChecker.cpp ./src/BigInteger/BigUnsigned.cc ./src/BigInteger/BigUnsignedInABase.cc ./src/BigInteger/BigIntegerUtils.cc ./src/BigInteger/BigInteger.cc
OBJECTS= $(SOURCES:.cpp=.o)
BIN_DIR = ./bin/
WINDRES = windres

#============================================
#=Operating system specific compiler options=
#============================================

ifeq 	($(OS),Windows_NT)
	EXECUTABLE := bin/SeedGenerator.exe
	SOURCES += ./src/sgIcon.rc
else
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
endif

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@if [ -d "./bin" ]; then \
        echo "bin folder exists"; else\
		mkdir bin; \
    fi
	$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

src/sgIcon.res: src/sgIcon.rc
	$(WINDRES) $< -o $@

clean:
	rm ./src/*.o
