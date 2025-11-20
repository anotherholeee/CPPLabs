cmake_minimum_required(VERSION 4.0)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4 main.cpp
        menu.cpp
        menu.h
        computer.cpp
        computer.h
        deque.cpp
        deque.h)
