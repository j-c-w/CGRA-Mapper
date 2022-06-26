#!/bin/bash

if [[ $# -ne 3 ]]; then
	echo "Usage: $0 <param_skeleton file> <operations json file> < param_file>"
	exit 1
fi

cat $1 $2 > $3
echo "}" >> $3
