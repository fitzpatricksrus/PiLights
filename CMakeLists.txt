cmake_minimum_required(VERSION 3.13)
project(PiLights)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(PiLights
        monochrome/DebugMonoLampMatrixHardware.cpp
        monochrome/DebugMonoLampMatrixHardware.h
        monochrome/MonoLampHardware.cpp
        monochrome/MonoLampHardware.h
        monochrome/MonoLampMatrixHardware.cpp
        monochrome/MonoLampMatrixHardware.h
        monochrome/MonoLampSet.cpp
        monochrome/MonoLampSet.h
        monochrome/PiLampHardware.cpp
        monochrome/PiLampHardware.h
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
        utils/TThread.cpp
        utils/TThread.h
        utils/FixedExecutionTimeCode.cpp
        utils/FixedExecutionTimeCode.h
        utils/RunningStat.cpp
        utils/RunningStat.h
        )

find_library(PIGPIOLIB libpigpio.so)
TARGET_LINK_LIBRARIES(PiLights "${PIGPIOLIB}")

