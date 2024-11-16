cmake_minimum_required(VERSION 3.29)
project(Chapter06ex)

add_compile_options("-Wall")
set(CMAKE_CXX_STANDARD 20)
add_executable(Chapter06ex
        main.cc
        algo.cpp
)
