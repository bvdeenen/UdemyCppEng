cmake_minimum_required(VERSION 3.29)
project(Chapter02)

set(CMAKE_CXX_STANDARD 20)

include_directories(Lib)

add_executable(Chapter02
    Lib/lib.cc
    start.cc
        bart.cpp
        Exercise/Exercise/AdFunctions.cc
)
