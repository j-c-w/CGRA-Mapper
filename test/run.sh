#!/bin/bash

f=$1
shift

if [[ ! -f $f ]]; then
	echo "Expected file, but found non-file $f"
	exit 1
fi
echo "Building $f"

opt -load ../build/src/libmapperPass.so -mapperPass $f "$@"
