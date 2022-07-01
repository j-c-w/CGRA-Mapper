#!/bin/bash

if [[ $# -lt 3 ]]; then
	echo "Usage: $0 <Architecture parameters file> <Loops benchmark directory> <output directory> [optional extra flags to pass to run_tests_against.sh]"
	exit 1
fi

param_file=$1
bmarks=$2
output=$3
shift 3

# This script doesn't need this parameter as much because
# these only require 9,000 compiles per benchmark
# rather than the 9 million or so required by the full
# benchmarking run.
fraction_to_run=0.2

mkdir -p $output/stdout

echo "Starting $param_file without rules"
./run_tests_against.sh $fraction_to_run $param_file $bmarks temp_architecture_no_rules $@ &> $output/stdout/no_rules.out
cp temp_architecture_no_rules/run_output.old $output/no_rules.out
echo "Starting $param_file with greedy"
./run_tests_against.sh $fraction_to_run $param_file $bmarks temp_architecture_greedy --use-greedy $@ &> $output/stdout/greedy.out
cp temp_architecture_greedy/run_output.old $output/greedy.out
echo "Staring $param_file  with rewriter"
./run_tests_against.sh $fraction_to_run $param_file $bmarks temp_architecture_rewriter --use-rewriter $@ &> $output/stdout/rewriter.out
cp temp_architecture_rewriter/run_output.old $output/rewriter.out
