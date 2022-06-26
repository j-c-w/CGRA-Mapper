#!/bin/bash

if [[ $# -ne 1 ]]; then
	echo "Usage: $0 <number of loops> <reduction factor>"
	echo "Reduction factor is to allow benchmarking just a fraction of the total benchmarks to reduce the computation demand."
	exit 1
fi


