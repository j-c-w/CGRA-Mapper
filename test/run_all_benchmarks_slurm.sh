#!/bin/zsh

if [[ $# -ne 3 ]]; then
	echo "Usage: $0 <loop folder> <number of loops to use as architectures> <reduction factor>"
	echo "Reduction factor is to allow benchmarking just a fraction of the total benchmarks to reduce the computation demand."
	exit 1
fi

benchmark_folder=$1
num_to_use=$2
fraction_to_run=$3

for file in $(find $benchmark_folder -name "loop*.c" -print0 | sort -z); do
	files+=($file)
done
files=( $(python3 reducer.py --number $num_to_use ${files[@]}) )
number=0

for loop in ${files[@]}; do
	number=$(( number + 1 ))
	sbatch execute_slurm.sh $loop $number $benchmark_folder $fraction_to_run
done
