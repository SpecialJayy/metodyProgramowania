cmake_minimum_required(VERSION 4.0)
project(metodyProgramowania)

set(CMAKE_CXX_STANDARD 20)

add_executable(metodyProgramowania main.cpp
        z1/z1.cpp
        z1/z2.cpp
        z2/z1.cpp
        libraries/libFile.h
        libraries/libFile.cpp)
