cmake_minimum_required(VERSION 3.16.3)
project(proj1)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS
        data_structures/Graph.h
        data_structures/read.h)

set(PROJECT_SOURCES
        src/main.cpp
        data_structures/Graph.cpp
        data_structures/read.cpp
        src/ex1.cpp
        src/ex1.h
        src/ex3.cpp
        src/ex3.h)

add_executable(proj1
        ${PROJECT_HEADERS}
        ${PROJECT_SOURCES})