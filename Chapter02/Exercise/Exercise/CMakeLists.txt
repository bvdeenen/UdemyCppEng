cmake_minimum_required(VERSION 3.29)
project(Chapter02Exercise)

set(CMAKE_CXX_STANDARD 20)

include_directories(Lib)

add_executable(Chapter02Exercise
        main.cc
        AdFunctions.cc
)
