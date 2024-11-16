cmake_minimum_required(VERSION 3.29)
project(Classes)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Classes
    Main.cc
    Weapons.cc)
