#!/bin/bash

if [[ $# -ne 2 ]]; then
	echo "Usage: $0 <number of loops> <reduction factor>"
	echo "Reduction factor is to allow benchmarking just a fraction of the total benchmarks to reduce the computation demand."
	exit 1
fi

fraction_to_run=$2
for loop in $(seq 1 $1); do
	srun --cpus-per-task 40 --mem=40GB -t 180 execute_slurm.sh $loop $fraction_to_run &
done
