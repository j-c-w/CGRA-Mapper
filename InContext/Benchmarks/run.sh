#!/bin/bash

set -ex # Dont' delete this flag --- arg parsing requires this for some reason --- I don't know why it doesn't show the print but does show this.
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
