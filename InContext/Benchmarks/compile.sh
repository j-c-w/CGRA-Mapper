#!/bin/zsh

set -e

typeset -a use_llvm_cannonicalizer
zparseopts -D -E -use-llvm-cannonicalizer=use_llvm_cannonicalizer

if [[ $# -ne 1 ]]; then
	echo "Usage: $0 <filename>"
	exit 1
fi

newfilename=${1/.cpp/}.bc
# Use O3 for the performance comparison rather than the works/not works
clang -Xclang -disable-O0-optnone -emit-llvm -fno-slp-vectorize -fno-unroll-loops -O2 -o $newfilename -c ${1}

echo "Have ${use_llvm_cannonicalizer[@]} args"
if [[ ${#use_llvm_cannonicalizer[@]} -gt 0 ]]; then
echo "Using LLVM Cannonicalizer"
	opt -instcombine -aggressive-instcombine $newfilename -S -o $newfilename
fi
#llvm-dis fir.bc -o fir.ll
