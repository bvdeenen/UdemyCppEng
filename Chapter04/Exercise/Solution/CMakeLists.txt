cmake_minimum_required(VERSION 3.29)
project(Solution)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Solution
    IteratorLib.h
    main.cc)
