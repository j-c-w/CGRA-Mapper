#!/bin/bash

# Get clang: the nix clang doesn't support non-native targets for llvm-mca.
git clone https://github.com/llvm/llvm-project
mkdir build
mkdir install
cd build
# build with clang
cmake ../llvm-project/llvm -DCMAKE_INSTALL_PREFIX=$PWD/../install -DLLVM_ENABLE_PROJECTS=clang -DCMAKE_BUILD_TYPE=Release
make -j
make install -j
