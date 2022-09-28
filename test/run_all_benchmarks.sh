#!/bin/zsh

# This script runs using the rewriter
typeset -a plot_only # Only plot data, don't gather it
typeset -a test_loops # Which loop numbers to test.
typeset -a gather_only # only gather data don't plot it
typeset -a run_individual_rulesets # run tests for the individual rulests
zparseopts -D -E -- -plot-only=plot_only -test-loops:=test_loops -gather-only=gather_only -run-individual-rulesets=run_individual_rulesets

if [[ $# -ne 3 ]]; then
	echo "Usage: $0 reduction_rate benchmarks_folder temp_folder"
	echo "Got args $@"
	exit 1
fi

reduction_rate=$1 #Reduce teh computation load --- 1.0 means run everything, 0.0 mean snothing.
folder=$2
target_files=( $(find $folder -name "loop*.c") )
temp_folder=$3
if [[ ${#test_loops} -gt 0 ]]; then
	echo "Testing loops ${test_loops[@]} only"
fi

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
				if [[ $(basename -- $tloop) == $(basename $file) ]]; then
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
		echo "Starting with greedy $file"
		./run_tests_against.sh $reduction_rate $file $folder $temp_folder --use-greedy &> run_all_benchmarks_outputs/stdout/${bfile}.greedy
		mv $temp_folder/run_output.old run_all_benchmarks_outputs/stdout/${bfile}.greedy.output
		echo "Starting with rewriter $file"
		./run_tests_against.sh $reduction_rate $file $folder $temp_folder --use-rewriter &> run_all_benchmarks_outputs/stdout/${bfile}.rewriter
		mv $temp_folder/run_output.old run_all_benchmarks_outputs/stdout/${bfile}.rewriter.output
		echo "Staring with LLVM rewriter $file"
		./run_tests_against.sh $reduction_rate $file $folder $temp_folder --use-llvm &> run_all_benchmarks_outputs/stdout/${bfile}.llvm
		mv $temp_folder/run_output.old run_all_benchmarks_outputs/stdout/${bfile}.llvm.output

		# Run the rewriter with just the boolean ruleset enabled.
		if [[ ${#run_individual_rulesets} -gt 0 ]]; then
			echo "Starting with logic-as-bool  $file"
			./run_tests_against.sh $reduction_rate $file $folder $temp_folder --use-rewriter --logic-as-bool-rules &> run_all_benchmarks_outputs/stdout/${bfile}.logic_as_bool
			mv $temp_folder/run_output.old run_all_benchmarks_outputs/stdout/${bfile}.logic_as_bool.output

			# echo "Starting with fp-rules $file"
			echo "Starting with fp rules  $file"
			./run_tests_against.sh $reduction_rate $file $folder $temp_folder --use-rewriter --fp-rules &> run_all_benchmarks_outputs/stdout/${bfile}.fp_rules
			mv $temp_folder/run_output.old run_all_benchmarks_outputs/stdout/${bfile}.fp_rules.output

			echo "Starting with int-rules $file"
			./run_tests_against.sh $reduction_rate $file $folder $temp_folder --use-rewriter --int-rules &> run_all_benchmarks_outputs/stdout/${bfile}.int_rules
			mv $temp_folder/run_output.old run_all_benchmarks_outputs/stdout/${bfile}.int_rules.output

			echo "Starting with all-rules $file"
			./run_tests_against.sh $reduction_rate $file $folder $temp_folder --use-rewriter --all-rules &> run_all_benchmarks_outputs/stdout/${bfile}.all_rules
			mv $temp_folder/run_output.old run_all_benchmarks_outputs/stdout/${bfile}.all_rules.output
		fi
	done
fi

# now, create the data files.

get_successes() {
	local fname=$1
	local outfile=$2
	local bybmark_out=run_all_benchmarks_outputs/${outfile}_by_benchmark

	local input_file=run_all_benchmarks_outputs/stdout/$fname

	# kernel.cpp is the base file --- it's the one the accelerator was designed for :)
	if [[ -f $input_file ]] then
		# Use a python script for this because it involves some complicated
		# tallying.  But we can apply grep first to keep the size
		# of the inputs down a bit.
		touch $bybmark_out
		./get_results_by_benchmark.sh $fname $input_file $bybmark_out

		# Also get the overall successes
		succ=$(cat $input_file | grep --binary-files=text "^Have" | cut -f2 -d ' ')
		fails=$(cat $input_file | grep --binary-files=text "^Have" | cut -f4 -d ' ')
		echo "$fname,$succ,$fails" >> run_all_benchmarks_outputs/$outfile
	fi
}
if [[ ${#gather_only} -eq 0 ]]; then
	# clear them incase we are running --plot-only
	echo -n "" > run_all_benchmarks_outputs/no_rules_data
	echo -n "" > run_all_benchmarks_outputs/llvm_data
	echo -n "" > run_all_benchmarks_outputs/greedy_data
	echo -n "" > run_all_benchmarks_outputs/rewriter_data

	echo -n "" > run_all_benchmarks_outputs/no_rules_data_by_benchmark
	echo -n "" > run_all_benchmarks_outputs/llvm_data_by_benchmark
	echo -n "" > run_all_benchmarks_outputs/greedy_data_by_benchmark
	echo -n "" > run_all_benchmarks_outputs/rewriter_data_by_benchmark

	if [[ ${#run_individual_rulesets} -gt 0 ]]; then
		echo -n "" > run_all_benchmarks_outputs/logic_as_bool_data
		echo -n "" > run_all_benchmarks_outputs/int_rules_data
		echo -n "" > run_all_benchmarks_outputs/fp_rules_data
		echo -n "" > run_all_benchmarks_outputs/all_rules_data

		echo -n "" > run_all_benchmarks_outputs/logic_as_bool_data_by_benchmark
		echo -n "" > run_all_benchmarks_outputs/int_rules_data_by_benchmark
		echo -n "" > run_all_benchmarks_outputs/fp_rules_data_by_benchmark
		echo -n "" > run_all_benchmarks_outputs/all_rules_data_by_benchmark
	fi

	for file in ${target_files[@]}; do
		bfile=$(basename $file)

		get_successes ${bfile}.no_rules no_rules_data
		get_successes ${bfile}.llvm llvm_data
		get_successes ${bfile}.greedy greedy_data
		get_successes ${bfile}.rewriter rewriter_data

		if [[ ${#run_individual_rulesets} -gt 0 ]]; then
			get_successes ${bfile}.logic_as_bool logic_as_bool_data
			get_successes ${bfile}.int_rules int_rules_data
			get_successes ${bfile}.fp_rules fp_rules_data
			get_successes ${bfile}.all_rules all_rules_data
		fi
	done

	python plot_successes.py run_all_benchmarks_outputs/graph.png run_all_benchmarks_outputs/no_rules_data run_all_benchmarks_outputs/llvm_data run_all_benchmarks_outputs/greedy_data run_all_benchmarks_outputs/rewriter_data
	python plot_successes_by_benchmark.py run_all_benchmarks_outputs/graph_by_benchmark.png run_all_benchmarks_outputs/no_rules_data_by_benchmark run_all_benchmarks_outputs/llvm_data_by_benchmark  run_all_benchmarks_outputs/greedy_data_by_benchmark run_all_benchmarks_outputs/rewriter_data_by_benchmark

	if [[ ${#run_individual_rulesets} -gt 0 ]]; then
		python plot_successes.py ruleset_successes.png run_all_benchmarks_outputs/int_rules_data run_all_benchmarks_outputs/fp_rules_data run_all_benchmarks_outputs/logic_as_bool_data run_all_benchmarks_outputs/all_rules_data --rulesets
	fi
fi
