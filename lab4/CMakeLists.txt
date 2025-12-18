cmake_minimum_required(VERSION 4.0)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4 main.cpp
        menu.cpp
        menu.h
        computer.cpp
        computer.h
        monoblock.cpp
        monoblock.h
        laptop.cpp
        laptop.h
        tablet.cpp
        tablet.h
        deque.cpp
        deque.h)
