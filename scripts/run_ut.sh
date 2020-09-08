#!/bin/bash

currpath=$(dirname "$0")
basepath=$(cd "$currpath/../" || exit; pwd)

cd "$basepath"/ || exit

main() {
    mkdir -p cmake_build/
    cd cmake_build/ || exit
    rm -rf ./tests
    cmake .. -DENABLE_UNIT_TESTS=ON || {
        error_exit "Failed to cmake."
    }

    cmake --build . || {
        error_exit "Failed to make."
    }

    ./tests || {
        error_exit "Failed to test."
    }
}

error_exit() {
    echo
    echo Error: "$@"
    echo "----------------------------------------------------------------------"
    echo
    exit 1
}

main "$@"
exit 0
