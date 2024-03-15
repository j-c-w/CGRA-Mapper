#!/bin/zsh

typeset -a rewriter_only print_used_rules
zparseopts -D -E -rewriter-only=rewriter_only -print-used-rules=print_used_rules

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
fraction_to_run=0.5

# The print-used-rules flag only works for the egraph rewriter backend iirc.
# Note that Egg (Egrpah library) is a bit buggy, so enabling this reduces
# gthe successful compile rate.
rewriter_extra_flags=""
if [[ ${#print_used_rules} -gt 0 ]]; then
	rewriter_extra_flags="$extra_flags --print-used-rules"
fi

mkdir -p $output/stdout
mkdir -p $output/{temp_architecture_greedy,temp_architecture_llvm,temp_architecture_no_rules,temp_architecture_rewriter}

if [[ ${#rewriter_only} -eq 0 ]]; then
	echo "Starting $param_file without rules"
	./run_tests_against.sh $fraction_to_run $param_file $bmarks $output/temp_architecture_no_rules $@ &> $output/stdout/no_rules.out
	cp $output/temp_architecture_no_rules/run_output.old $output/no_rules.out
	rm -rf $output/temp_architecture_no_rules # Delete these to keep sizes down.  Maybe we really want to keep them?
	echo "Starting $param_file with greedy"
	./run_tests_against.sh $fraction_to_run $param_file $bmarks $output/temp_architecture_greedy --use-greedy $@ &> $output/stdout/greedy.out
	cp $output/temp_architecture_greedy/run_output.old $output/greedy.out
	rm -rf $output/temp_architecture_greedy
	echo "Starting $param_file with llvm"
	./run_tests_against.sh $fraction_to_run $param_file $bmarks $output/temp_architecture_llvm --use-llvm $@ &> $output/stdout/llvm.out
	cp $output/temp_architecture_llvm/run_output.old $output/llvm.out
	rm -rf $output/temp_architecture_llvm
	echo "Starting $param_file with egg"
	./run_tests_against.sh $fraction_to_run $param_file $bmarks $output/temp_architecture_egg --use-egraphs $@ &> $output/stdout/egg.out
	cp $output/temp_architecture_llvm/run_output.old $output/egg.out
	rm -rf $output/temp_architecture_llvm
fi

echo "Staring $param_file  with rewriter"
./run_tests_against.sh $rewriter_extra_flags $fraction_to_run $param_file $bmarks $output/temp_architecture_rewriter --use-static-egraphs $@ &> $output/stdout/rewriter.out
cp $output/temp_architecture_rewriter/run_output.old $output/rewriter.out
rm -rf $output/temp_architecture_rewriter
