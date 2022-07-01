#!/bin/zsh

typeset -a plot_only
zparseopts -D -E -plot-only=plot_only
if [[ $# -ne 0 ]]; then
	echo "Usage: $0 [--plot-only]"
	exit 1
fi

# Benchmark each of these architectures
if [[ ${#plot_only} == 0 ]]; then
    pushd ../../test

    ./run_against_architectures.sh ../benchmark_scripts/architectures/cca.json ../Loops3 cca_output
	# Use the FP rules also for maeri since it supports FP expressions
    ./run_against_architectures.sh ../benchmark_scripts/architectures/maeri.json ../Loops3 maeri_output --fp-rules --int-rules
    ./run_against_architectures.sh ../benchmark_scripts/architectures/revamp.json ../Loops3 revamp_output
	# Use the stochastic ruleset for SC-CGRA since it is a stochastic cgra.
    ./run_against_architectures.sh ../benchmark_scripts/architectures/sc-cgra.json ../Loops3 sc_cgra_output --stochastic-rules --int-rules

    popd
fi

# Get these results and plot the appropriate graphs.
get_compile_rates() {
    local data_folder=$1
    local output_file=$2
    local archname=$3
    echo -n "" > $output_file

    # Get the successes and the fails for each.
    norules_succ=$(cat $data_folder/stdout/no_rules.out | grep --binary-files=text "^Have" | cut -f2 -d ' ')
    norules_fails=$(cat $data_folder/stdout/no_rules.out | grep --binary-files=text "^Have" | cut -f4 -d ' ')
    echo "OpenCGRA,$norules_succ,$norules_fails" >> $output_file
	local bybmark_out=$data_folder/no_rules_by_benchmark
	# Use a python script for this because it involves some complicated
	# tallying.  But we can apply grep first to keep the size
	# of the inputs down a bit.
	touch $bybmark_out
	python get_results_by_benchmark.py norules_${archname} $data_folder/no_rules.out $bybmark_out

    rewriter_succ=$(cat $data_folder/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f2 -d ' ')
    rewriter_fails=$(cat $data_folder/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f4 -d ' ')
    echo "FlexC,$rewriter_succ,$rewriter_fails" >> $output_file
	local bybmark_out=$data_folder/rewriter_by_benchmark
	# Use a python script for this because it involves some complicated
	# tallying.  But we can apply grep first to keep the size
	# of the inputs down a bit.
	touch $bybmark_out
	python get_results_by_benchmark.py rewriter_${archname} $data_folder/rewriter.out $bybmark_out

    greedy_succ=$(cat $data_folder/stdout/greedy.out | grep --binary-files=text "^Have" | cut -f2 -d ' ')
    greedy_fails=$(cat $data_folder/stdout/greedy.out | grep --binary-files=text "^Have" | cut -f4 -d ' ')
    echo "Greedy Rewriter,$greedy_succ,$greedy_fails" >> $output_file
	local bybmark_out=$data_folder/greedy_by_benchmark
	# Use a python script for this because it involves some complicated
	# tallying.  But we can apply grep first to keep the size
	# of the inputs down a bit.
	touch $bybmark_out
	python get_results_by_benchmark.py greedy_${archname} $data_folder/greedy.out $bybmark_out
}

mkdir -p data
get_compile_rates ../../test/cca_output data/cca
get_compile_rates ../../test/maeri_output data/maeri
get_compile_rates ../../test/revamp_output data/revamp
get_compile_rates ../../test/sc_cgra_output data/sc_cgra

# Now plot
python plot_case_studies.py data/cca data/maeri data/revamp data/sc_cgra
