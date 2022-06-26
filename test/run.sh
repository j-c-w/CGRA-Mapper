#!/bin/bash

set -x
lmapper=$1
shift
f=$1
shift

if [[ ! -f $f ]]; then
	echo "Expected file, but found non-file $f"
	exit 1
fi
echo "Building $f"

set -x
opt -load $lmapper -mapperPass $f "$@"
echo "Finished $f"