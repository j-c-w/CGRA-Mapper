#!/bin/bash

if [[ $# -ne 2 ]]; then
	echo "Usage: $0 <operations json file> < param_file>"
	exit 1
fi

cat param_skeleton $1 > $2
echo "}" >> $2
