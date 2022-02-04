#!/bin/bash

if [[ $# -ne 1 ]]; then
	echo "Usage: $0 <operations json file>"
	exit 1
fi

cat param_skeleton $1 > param.json
echo "}" >> param.json
