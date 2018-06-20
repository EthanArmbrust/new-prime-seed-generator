cmake_minimum_required(VERSION 3.1)
project (new-prime-seed-generator)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-O3 -std=c++11 -pthread")
set(CMAKE_MODULE_LINKER_FLAGS = "-static-libgcc -static-libstdc++")
set(CLIP_EXAMPLES OFF CACHE BOOL "turn off example")
set(CLIP_TESTS OFF CACHE BOOL "turn off tests")

add_subdirectory(src/clip)

add_executable(SeedGenerator src/main.cpp src/Random.cpp src/logChecker.cpp src/BigInteger/BigUnsigned.cc src/BigInteger/BigInteger.cc src/BigInteger/BigUnsignedInABase.cc src/BigInteger/BigIntegerUtils.cc)

target_link_libraries(SeedGenerator clip)
