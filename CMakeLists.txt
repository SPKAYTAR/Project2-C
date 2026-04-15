cmake_minimum_required(VERSION 4.2)
project(Digital_Library)

set(CMAKE_CXX_STANDARD 20)

add_executable(Digital_Library main.cpp
        exceptions/LibraryManagerExceptions.h
        exceptions/LibraryManagerExceptions.cpp)
