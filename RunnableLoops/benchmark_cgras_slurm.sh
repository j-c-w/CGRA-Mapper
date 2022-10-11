#!/bin/zsh

if [[ $# -ne 3 ]]; then
    echo "Usage: $0 <loop folder> <number of loops to use as architectures> <reduction factor>"
    exit 1
fi

benchmark_folder=$1
num_to_use=$2
fraction_to_run=$3

typeset -a files
for file in $(find $benchmark_folder -name "*.c" -print0 | sort -z); do
    files+=($file)
done
files=( $(python3 ../test/reducer.py --number $num_to_use ${files[@]}) )
number=0

for loop in ${files[@]}; do
    number=$((number + 1))
    echo "Submitting execute_slurm_benchmark_cgras.sh $loop $number $benchmark_folder $fraction_to_run"
    sbatch execute_slurm_benchmark_cgras.sh $loop $number $benchmark_folder $fraction_to_run
done