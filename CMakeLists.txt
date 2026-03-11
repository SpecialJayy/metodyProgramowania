cmake_minimum_required(VERSION 4.0)
project(metodyProgramowania)

set(CMAKE_CXX_STANDARD 20)

add_library(Libraries libraries/libFile.cpp libraries/libFile.h)

add_executable(zadanie_2_1 z2/z1.cpp)

target_link_libraries(zadanie_2_1 Libraries)

add_executable(metodyProgramowania main.cpp
        z1/z1.cpp
        z1/z2.cpp
        z2/z1.cpp)
