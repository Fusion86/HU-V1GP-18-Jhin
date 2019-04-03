#!/bin/sh

mkdir -p build
cd build

if grep "Raspberry" /proc/device-tree/model &>/dev/null; then
    # Compile on Raspberry Pi
    cmake -D CMAKE_BUILD_TYPE=Debug ..
    make
else
    # Check if we need to use MSYS or normal Makefiles (MSYS is for Windows)
    if uname -a | grep -q 'MSYS_NT'; then
        GEN="MSYS Makefiles"
    else
        GEN="Unix Makefiles"
    fi

    echo "-- Using generator: $GEN"

    # Fake compile (to check if the code can compile, all BrickPi functions are stubbed)
    cmake -D CMAKE_BUILD_TYPE=Debug -D FAKE_BRICKPI=1 -G "$GEN" ..
    make
fi