#!/bin/bash

$(dirname $(which $0))/../test/run.sh $(dirname $(which $0))/../build/src/libmapperPass.so "$@"
