cmake_minimum_required(VERSION 3.29)
project(Chapter06)

set(CMAKE_CXX_STANDARD 23)
# if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
# add_compile_options("-O0")
# endif()

add_executable(Chapter06
    chronos.cc
)
