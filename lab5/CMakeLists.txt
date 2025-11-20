rm -Recurse -Force lab5/.gitcmake_minimum_required(VERSION 4.0)
project(lab5)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab5 main.cpp
        computer.cpp
        computer.h
        menu.cpp
        menu.h
        deque.cpp
        deque.h)

