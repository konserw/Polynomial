#!/bin/sh
set -e #break script on non-zero exitcode from any command
set -x #display command being executed

CTEST_OUTPUT_ON_FAILURE=ON
export CTEST_OUTPUT_ON_FAILURE

cmake -E make_directory build
cmake -E chdir build cmake \
    -G Ninja \
    -DENABLE_EXAMPLES=on \
    ${CMAKE_PREFIX_PATH:+"-DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}"} \
    ${COVERALLS_SERVICE_NAME:+"-DCMAKE_BUILD_TYPE=Debug"} \
    ${COVERALLS_SERVICE_NAME:+"-DCMAKE_CXX_FLAGS='--coverage'"} \
    ${VALGRIND_TESTS:+"-DVALGRIND_TESTS=${VALGRIND_TESTS}"} \
    ..
cmake --build build
cmake --build build --target test

