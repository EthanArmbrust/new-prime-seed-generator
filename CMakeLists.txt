cmake_minimum_required(VERSION 3.1)
project (new-prime-seed-generator)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-O3 -std=c++11 -pthread")
set(CMAKE_MODULE_LINKER_FLAGS = "-static-libgcc -static-libstdc++")

add_library(main-obj OBJECT src/main.cpp)
add_library(random-obj OBJECT src/Random.cpp)
add_library(log-obj OBJECT src/logChecker.cpp)
add_library(BigUnsigned-obj OBJECT src/BigInteger/BigUnsigned.cc)
add_library(BigUInBase-obj OBJECT src/BigInteger/BigUnsignedInABase.cc)
add_library(BigIntUtils-obj OBJECT src/BigInteger/BigIntegerUtils.cc)
add_library(BigInteger-obj OBJECT src/BigInteger/BigInteger.cc)
add_subdirectory(src/clip)



add_executable(SeedGenerator $<TARGET_OBJECTS:random-obj> $<TARGET_OBJECTS:log-obj> $<TARGET_OBJECTS:main-obj> $<TARGET_OBJECTS:BigUnsigned-obj> $<TARGET_OBJECTS:BigUInBase-obj> $<TARGET_OBJECTS:BigIntUtils-obj> $<TARGET_OBJECTS:BigInteger-obj>)

target_link_libraries(SeedGenerator clip)
