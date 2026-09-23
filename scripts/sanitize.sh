#!/usr/bin/env sh
set -eu

rm -rf build-sanitize
cmake -S . -B build-sanitize -DCMAKE_BUILD_TYPE=Debug   -DCMAKE_C_FLAGS="-fsanitize=address,undefined -fno-omit-frame-pointer"
cmake --build build-sanitize --parallel
ctest --test-dir build-sanitize --output-on-failure
