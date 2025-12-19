cmake_minimum_required(VERSION 4.0)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3 main.cpp
        computer.cpp
        computer.h
        menu.cpp
        menu.h
        monoblock.cpp
        monoblock.h
        laptop.cpp
        laptop.h
        tablet.cpp
        tablet.h
)
