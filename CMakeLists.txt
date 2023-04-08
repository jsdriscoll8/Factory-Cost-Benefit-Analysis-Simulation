cmake_minimum_required(VERSION 3.24)
project(M2OEP_jsdrisco)
set(CMAKE_CXX_STANDARD 14)

add_executable(MAIN
        CarFactory.cpp
        CarFactory.h
        ChipFactory.cpp
        ChipFactory.h
        Employee.cpp
        Employee.h
        Factory.cpp
        Factory.h main.cpp)


add_executable(TESTING
        CarFactory.cpp
        CarFactory.h
        ChipFactory.cpp
        ChipFactory.h
        Employee.cpp
        Employee.h
        Factory.cpp
        Factory.h testing.cpp)