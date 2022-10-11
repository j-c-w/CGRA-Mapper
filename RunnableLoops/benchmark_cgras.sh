#!/bin/zsh

typeset -a plot_only # Only plot data, don't gather it
typeset -a test_loops # Which loop numbers to test.
typeset -a gather_only # only gather data don't plot it
zparseopts -D -E -- -plot-only=plot_only -test-loops:=test_loops -gather-only=gather_only

# Conceptually, this script is similar to the run_all_benchmarks.sh
# script --- it is designed to work with
# the hash-based naming system that is used
# to track performance between loops.
if [[ $# -ne 3 ]]; then
    echo "Usage: $0 reduction_rate benchmarks_folder temp_folder"
    echo "Args were $@"
    exit 1
fi

reduction_rate=$1
folder=$2
# Note that target_files here means the 
# target files to use as accelerator designs.
# reduction_rate is to reduce the fraction of
# stuff compiled to those files.
target_files=( $(find $folder -name "*.c") )
temp_folder=$3

mkdir -p run_cgra_benchmark_outputs/stdout
current_dir=$PWD

if [[ ${#plot_only} -eq 0 ]]; then
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

        echo "Starting bencharmk $file"
        bfile=$(basename $file)
        pushd ../test
        ./run_tests_against.sh $reduction_rate ../RunnableLoops/$file ../RunnableLoops/$folder ../RunnableLoops/$temp_folder &> $current_dir/run_cgra_benchmark_outputs/stdout/${bfile}.rewriter --use-latencies
        mv ../RunnableLoops/$temp_folder/run_output.old ../RunnableLoops/run_cgra_benchmark_outputs/stdout/${bfile}.rewriter.output
        popd
    done
fi

get_iis() {
    local fname=$1

    local datafile=run_cgra_benchmark_outputs/stdout/$(basename $fname).rewriter.output
    echo "Looking at $datafile"

    cat $datafile | grep -A10 -B4 --binary-files=text Mapping:success &>> run_cgra_benchmark_outputs/maps
}

if [[ ${#gather_only} -eq 0 ]]; then
    ii_file=run_cgra_benchmark_outputs/maps
    rm $ii_file
    touch $ii_file
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
        get_iis $file
    done

    python fix_ii_file.py $ii_file $ii_file.reformatted
    python plot_speedups.py data/A5.times data/A5.iterations $ii_file.reformatted
fi