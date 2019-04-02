#!/bin/sh

mkdir -p build
cd build

if grep "Raspberry" /proc/device-tree/model; then
    # Compile on Raspberry Pi
    cmake -D CMAKE_BUILD_TYPE=Debug ..
    make
else
    # Cross-compile on linux for Raspberry Pi
    # Requires that you have https://github.com/raspberrypi/tools in $HOME/rpi (see Toolchain-BrickPi.cmake)
    cmake -D CMAKE_BUILD_TYPE=Debug -D CMAKE_TOOLCHAIN_FILE=../Toolchain-BrickPi.cmake ..
    make
fi