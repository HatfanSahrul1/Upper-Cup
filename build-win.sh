#!/bin/bash
mkdir -p build-win
cd build-win
cmake .. -DCMAKE_TOOLCHAIN_FILE=../mingw-toolchain.cmake -Draylib_DIR=../raylib-win
make