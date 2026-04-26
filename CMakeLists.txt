cmake_minimum_required(VERSION 4.0)
project(metodyProgramowania)

set(CMAKE_CXX_STANDARD 20)

add_executable(metodyProgramowania
        z7/z1.cpp
        libraries/libArray.cpp
        libraries/libFile.cpp
        libraries/libArray.h
        libraries/libInput.cpp
        libraries/libGraph.cpp
        libraries/libGraph.h
        libraries/Stack.cpp
        libraries/Stack.h
        libraries/LinkedList.cpp
        libraries/LinkedList.h
        z7/z1.cpp
        libraries/libRand.cpp
        libraries/libRand.h)
