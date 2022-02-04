#!/bin/bash

set -eu

if [[ $# -ne 2 ]]; then
	echo "Usage: $0 <CGRA Design File> <Other Input Files Base Folder>"
	echo "Other files should all be in the format loopX.c (X a number)"
	exit 1
fi

## Build the CGRA.
cp $1 kernel.cpp

## Build the initial CGRA.
./compile.sh
./run.sh --build
./build_param.sh operations.json

shift

## Now run over all other input files.
for file in $(find $1 -name "loop*.c"); do
	cp $file kernel.cpp
	./compile.sh
	(timeout 2 ./run.sh && echo "Succeeded in building $file") || echo "Failed to build $file"
done
