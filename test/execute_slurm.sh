#!/bin/bash

if [[ $# -ne 2 ]]; then
	echo "Usage: $0 <loop number> <reduction rate>"
	exit 1
fi
loopno=$1
reduction_rate=$2 # Float from 0.0 to 1.0 --- how many loops to try
# and compile to each design to save time.

cd ~/nix
./nix-user-chroot ~/.nix bash -c "
cd ~/Projects/CGRA/CGRA-Mapper
nix-shell shell.nix --run '
set -x
cd test
./run_all_benchmarks.sh $reduction_rate ../Loops2 temp$loopno --gather-only --test-loops loop$loopno.c
'
"
