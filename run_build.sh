#!/bin/sh

if [ -n "$1" ]; then
    case "$1" in
        "--help")
            echo "Build script for testbed\n"
            echo "Usage:"
            echo "    ./build.sh [options]"
            echo "Options:"
            echo "    clean = Remove a build directory."
            ;;
        "--clean")
            if [ -d "build" ]; then
                cat build/install_manifest.txt | xargs -L1 dirname | sudo xargs rm -rv
                rm -rfv build
            fi
            ;;
    esac
else
    if [ ! -d "build" ]; then
        mkdir build
    fi
    cmake -S . -B build
    cmake --build build
    cmake --install build
fi
