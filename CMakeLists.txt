cmake_minimum_required(VERSION 3.14)
project(TestProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestProject main.cpp LampSet.cpp LampSet.h SimpleLampSet.cpp SimpleLampSet.h LampHardware.cpp LampHardware.h LampMatrix.cpp LampMatrix.h CompositeLampSet.cpp CompositeLampSet.h)