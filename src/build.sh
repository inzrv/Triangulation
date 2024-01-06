#!/bin/bash

# Check if the "build" directory exists, if not create it
if [ ! -d "build" ]; then
    mkdir build
fi

# Change to the "build" directory
cd build

# Run CMake to generate build files
cmake ..

# Compile the project using make
make
