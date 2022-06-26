#!/bin/zsh

# This script runs using the rewriter
typeset -a plot_only # Only plot data, don't gather it
typeset -a test_loops # Which loop numbers to test.
typeset -a gather_only # only gather data don't plot it
zparseopts -D -E -- -plot-only=plot_only -test-loops:=test_loops -gather-only=gather_only

if [[ $# -ne 3 ]]; then
	echo "Usage: $0 reduction_rate benchmarks_folder temp_folder"
	echo "Got args $@"
	exit 1
fi

reduction_rate=$1 #Reduce teh computation load --- 1.0 means run everything, 0.0 mean snothing.
# TODO implement.
folder=$2
target_files=( $(find $folder -name "loop*.c") )
temp_folder=$3

if [[ ${#plot_only} -eq 0 ]]; then
	# Store the stdout of everything to make debugging
	# easier.
	# Don't delete this to allow for parallelization.
	# rm -rf run_all_benchmarks_outputs
	mkdir -p run_all_benchmarks_outputs
	mkdir -p run_all_benchmarks_outputs/stdout

	for file in ${target_files[@]}; do
		if [[ ${#test_loops} -gt 0 ]]; then
			# If there are no test loops passed, run everything
			# by default.
			found="no"
			for tloop in ${test_loops[@]}; do
				if [[ $tloop == $(basename $file) ]]; then
					found="yes"
				fi
			done
			if [[ $found == "no" ]]; then
				continue
			fi
		fi

		echo "Starting benchmark $file"
		bfile=$(basename $file)
		./run_tests_against.sh $reduction_rate $file $folder $temp_folder &> run_all_benchmarks_outputs/stdout/${bfile}.no_rules
		mv $temp_folder/run_output.old run_all_benchmarks_outputs/stdout/${bfile}.no_rules.output
		echo "Starting with egraphs $file"
		./run_tests_against.sh $reduction_rate $file $folder $temp_folder --use-egraphs &> run_all_benchmarks_outputs/stdout/${bfile}.egraphs
		mv $temp_folder/run_output.old run_all_benchmarks_outputs/stdout/${bfile}.egraphs.output
		echo "Starting with greedy rewriter $file"
		./run_tests_against.sh $reduction_rate $file $folder $temp_folder --use-rewriter &> run_all_benchmarks_outputs/stdout/${bfile}.rewriter
		mv $temp_folder/run_output.old run_all_benchmarks_outputs/stdout/${bfile}.rewriter.output
	done
fi

# now, create the data files.

if [[ ${#gather_only} -eq 0 ]]; then
	# clear them incase we are running --plot-only
	echo -n "" > run_all_benchmarks_outputs/no_rules_data
	echo -n "" > run_all_benchmarks_outputs/egraphs_data
	echo -n "" > run_all_benchmarks_outputs/rewriter_data

	for file in ${target_files[@]}; do
		bfile=$(basename $file)
		norules_succ=$(cat run_all_benchmarks_outputs/stdout/${bfile}.no_rules | grep --binary-files=text "^Have" | cut -f2 -d ' ')
		norules_fails=$(cat run_all_benchmarks_outputs/stdout/${bfile}.no_rules | grep --binary-files=text "^Have" | cut -f4 -d ' ')
		echo "$bfile,$norules_succ,$norules_fails" >> run_all_benchmarks_outputs/no_rules_data

		egraph_succ=$(cat run_all_benchmarks_outputs/stdout/${bfile}.egraphs | grep --binary-files=text "^Have" | cut -f2 -d ' ')
		egraph_fails=$(cat run_all_benchmarks_outputs/stdout/${bfile}.egraphs | grep --binary-files=text "^Have" | cut -f4 -d ' ')
		echo "$bfile,$egraph_succ,$egraph_fails" >> run_all_benchmarks_outputs/egraphs_data

		rewriter_succ=$(cat run_all_benchmarks_outputs/stdout/${bfile}.rewriter | grep --binary-files=text "^Have" | cut -f2 -d ' ')
		rewriter_fails=$(cat run_all_benchmarks_outputs/stdout/${bfile}.rewriter | grep --binary-files=text "^Have" | cut -f4 -d ' ')
		echo "$bfile,$rewriter_succ,$rewriter_fails" >> run_all_benchmarks_outputs/rewriter_data
	done

	python plot_successes.py run_all_benchmarks_outputs/graph.png run_all_benchmarks_outputs/no_rules_data run_all_benchmarks_outputs/rewriter_data run_all_benchmarks_outputs/egraphs_data
fi
