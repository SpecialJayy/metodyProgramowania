cmake_minimum_required(VERSION 4.0)
project(metodyProgramowania)

set(CMAKE_CXX_STANDARD 20)

add_executable(metodyProgramowania
        z3/z4.cpp
        libraries/libArray.cpp
        libraries/libFile.cpp
        libraries/libArray.h
        libraries/libInput.cpp
        z3/z4.cpp)
