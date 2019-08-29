cmake_minimum_required(VERSION 3.14)
project(PiLights)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(monochrome)

add_executable(PiLights
        monochrome/MonoLampHardware.cpp
        monochrome/MonoLampHardware.h
        monochrome/MonoLampMatrixHardware.cpp
        monochrome/MonoLampMatrixHardware.h
        monochrome/MonoLampSet.cpp
        monochrome/MonoLampSet.h
        monochrome/SimpleMonoLampSet.cpp
        monochrome/SimpleMonoLampSet.h
        CompositeLampSet.cpp
        CompositeLampSet.h
        LampHardware.cpp
        LampHardware.h
        LampMatrix.cpp
        LampMatrix.h
        LampSet.cpp
        LampSet.h
        main.cpp
        PigpioLampMatrix.cpp
        PigpioLampMatrix.h
        SimpleLampSet.cpp
        SimpleLampSet.h
        TThread.cpp
        TThread.h)

find_library(PIGPIOLIB libpigpio.so)
TARGET_LINK_LIBRARIES(TestProject "${PIGPIOLIB}")
