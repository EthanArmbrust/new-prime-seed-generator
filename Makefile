#============================================
#=============Setting defaults===============
#============================================
CXX = g++
CXXFLAGS = -c -std=c++11 -O3
LDFLAGS = -static-libgcc -static-libstdc++
UNAME_S := $(shell uname -s)
FOR_WIN := FALSE
SOURCES = ./src/main.cpp ./src/Random.cpp ./src/logChecker.cpp ./src/BigInteger/BigUnsigned.cc ./src/BigInteger/BigUnsignedInABase.cc ./src/BigInteger/BigIntegerUtils.cc ./src/BigInteger/BigInteger.cc
OBJECTS= $(SOURCES:.cpp=.o)
BIN_DIR = ./bin/
WINDRES = windres
CLEANUP = ./src/*.o

#============================================
#=Operating system specific compiler options=
#============================================

ifeq 	($(OS),Windows_NT)
	EXECUTABLE := bin/SeedGenerator.exe
	SOURCES += ./src/sgIcon.res
	CLEANUP += ./src/*.res
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
		WINDRES := i686-w64-mingw32-windres
		SOURCES += ./src/sgIcon.res
		LDFLAGS += -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
		CLEANUP += ./src/*.res
	endif
endif

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@if [ -d "./bin" ]; then \
        echo "\033[1;36mBin folder already exists"; else\
		mkdir bin; \
	fi
	@echo "\033[1;34mLinking objects"
	@$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)

.cpp.o:
	@echo "\033[1;32mBuilding \033[0;32m$<"
	@$(CXX) $(CXXFLAGS) $< -o $@

src/sgIcon.res: src/sgIcon.rc
	@echo "\033[1;32mBuilding \033[0;32m$<"
	@$(WINDRES) $< -O coff -o $@

clean:
	@echo "\033[1;31mDeleting compiled objects..."
	@rm $(CLEANUP)
