cmake_minimum_required(VERSION 3.5)

project(rvalue LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(rvalue
    Main.cc
)

include(GNUInstallDirs)
install(TARGETS rvalue
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
