#!/bin/bash

## tool for getting the more interesting egrah dumps (i.e. the ones that greedy can't do)

if [[ $# -ne 3 ]]; then
	echo "Usage: $0 <egraph output folder> <greedy output folder> <output directory>"
fi

egraph_out=$1
greedy_out=$2
out=$3
i=1

mkdir -p $out

while [[ -f $egraph_out/${i}.stdout ]]; do

	if [[ ! -f $greedy_out/$i.output.json ]] && [[ -f $egraph_out/$i.output.json ]]; then
		cp $egraph_out/${i}.* $out
	fi

	i=$(( i + 1 ))
done
