cmake_minimum_required(VERSION 3.13)
project(PiLights)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestProject main.cpp LampSet.cpp LampSet.h SimpleLampSet.cpp SimpleLampSet.h LampHardware.cpp LampHardware.h LampMatrix.cpp LampMatrix.h CompositeLampSet.cpp CompositeLampSet.h PigpioLampMatrix.cpp PigpioLampMatrix.h)

find_library(PIGPIOLIB libpigpio.so)
TARGET_LINK_LIBRARIES(TestProject "${PIGPIOLIB}")
