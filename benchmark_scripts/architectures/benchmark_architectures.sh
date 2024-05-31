#!/bin/zsh

typeset -a plot_only
typeset -a use_slurm
typeset -a print_used_rules # the rule printer breaks the egraphs rewriter, so is disabled.
# note that currently (oct 2022), tenabling this falg also requires modifying lib.rs
zparseopts -D -E -plot-only=plot_only -slurm=use_slurm -print-used-rules=print_used_rules
if [[ $# -ne 0 ]]; then
	echo "Usage: $0 [--plot-only] [--slurm] [--print-used-rules]"
	exit 1
fi

benchmark_folder=../Loops4

if [[ ${#use_slurm[@]} -gt 0 ]]; then
	slurm="srun --cpus-per-task 40 --mem=590GB -t1-0:0 "
	use_slurm="_slurm.sh" # Run slurm version of each script.
	waiter=""
	echo "Using slurm, with paramters $slurm"
else
	slurm="zsh"
	use_slurm=""
	waiter="wait" # make sure to rejoin after each step to avoid
	# overloading the machine if not using slurm.
fi

run_architectures_with_rules() {
	local archfile=$1
	local archname=$2

	eval "$slurm ./run_against_architectures.sh$use_slurm $archfile $benchmark_folder ${archname}_int --rewriter-only --int-rules" & # Re-run the baseline, as some of the overall results use custom rulesets.
	eval "$waiter"
	eval "$slurm ./run_against_architectures.sh$use_slurm $archfile $benchmark_folder ${archname}_fp --rewriter-only --int-rules --fp-rules" &
	eval "$waiter"
	eval "$slurm ./run_against_architectures.sh$use_slurm $archfile $benchmark_folder ${archname}_stochastic --rewriter-only --int-rules --stochastic-rules" &
	eval "$waiter"
	eval "$slurm ./run_against_architectures.sh$use_slurm $archfile $benchmark_folder ${archname}_logic_as_bool --rewriter-only --int-rules --logic-as-bool-rules" &
	eval "$waiter"
	eval "$slurm ./run_against_architectures.sh$use_slurm $archfile $benchmark_folder ${archname}_all_rules --rewriter-only --int-rules --logic-as-bool-rules --fp-rules --stochastic-rules" &
	eval "$waiter"
}

# Benchmark each of these architectures
if [[ ${#plot_only} == 0 ]]; then
    pushd ../../test

	# note that --int-rules is implicit unless otherwise specified.
    eval "$slurm ./run_against_architectures.sh$use_slurm ../benchmark_scripts/architectures/cca.json $benchmark_folder cca_output" &
	eval "$waiter"
	# Use the FP rules also for maeri since it supports FP expressions
    eval "$slurm ./run_against_architectures.sh$use_slurm ../benchmark_scripts/architectures/maeri.json $benchmark_folder maeri_output --fp-rules --int-rules" &
	eval "$waiter"
    eval "$slurm ./run_against_architectures.sh$use_slurm ../benchmark_scripts/architectures/revamp.json $benchmark_folder revamp_output" &
	eval "$waiter"
	# Use the stochastic ruleset for SC-CGRA since it is a stochastic cgra.
    eval "$slurm ./run_against_architectures.sh$use_slurm ../benchmark_scripts/architectures/sc-cgra.json $benchmark_folder sc_cgra_output --stochastic-rules --int-rules" &
	eval "$waiter"

	# Get the data for the ruleset table -- this is more compute intensive, so re-gather the
	# data completely.
    eval "$slurm ./run_against_architectures.sh$use_slurm ../benchmark_scripts/architectures/cca.json $benchmark_folder cca_output_rules_metadata --print-used-rules --rewriter-only" &
	eval "$waiter"
    eval "$slurm ./run_against_architectures.sh$use_slurm ../benchmark_scripts/architectures/maeri.json $benchmark_folder maeri_output_rules_metadata --print-used-rules --fp-rules --int-rules --rewriter-only" &
	eval "$waiter"
    eval "$slurm ./run_against_architectures.sh$use_slurm ../benchmark_scripts/architectures/revamp.json $benchmark_folder revamp_output_rules_metadata --print-used-rules --rewriter-only" &
	eval "$waiter"
    eval "$slurm ./run_against_architectures.sh$use_slurm ../benchmark_scripts/architectures/sc-cgra.json $benchmark_folder sc_cgra_output_rules_metadata --print-used-rules --stochastic-rules --int-rules --rewriter-only" &
	eval "$waiter"

	# Run these architectures with the different rulesets to explore how those do.
	run_architectures_with_rules ../benchmark_scripts/architectures/cca.json cca_rules
	run_architectures_with_rules ../benchmark_scripts/architectures/maeri.json maeri_rules
	run_architectures_with_rules ../benchmark_scripts/architectures/revamp.json revamp_rules
	run_architectures_with_rules ../benchmark_scripts/architectures/sc-cgra.json sc-cgra_rules

	wait

    popd
fi

# Get these results and plot the appropriate graphs.
get_compile_rates() {
    local data_folder=$1
    local output_file=$2
    local archname=$3
	local out_folder=$4
    echo -n "" > $output_file

    # Get the successes and the fails for each.
    norules_succ=$(cat $data_folder/stdout/no_rules.out | grep --binary-files=text "^Have" | cut -f2 -d ' ')
    norules_fails=$(cat $data_folder/stdout/no_rules.out | grep --binary-files=text "^Have" | cut -f4 -d ' ')
	norules_total=$(cat $data_folder/stdout/no_rules.out | grep --binary-files=text "^Running over files" | cut -f4 -d ' ')
    echo "OpenCGRA,$norules_succ,$norules_fails,$norules_total" >> $output_file
	local bybmark_out=$out_folder/no_rules_by_benchmark
	# Use a python script for this because it involves some complicated
	# tallying.  But we can apply grep first to keep the size
	# of the inputs down a bit.
	touch $bybmark_out
	../../test/get_results_by_benchmark.sh norules_${archname} $data_folder/no_rules.out $bybmark_out

    rewriter_succ=$(cat $data_folder/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f2 -d ' ')
    rewriter_fails=$(cat $data_folder/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f4 -d ' ')
	rewriter_total=$(cat $data_folder/stdout/rewriter.out | grep --binary-files=text "^Running over files" | cut -f4 -d ' ')
    echo "FlexC,$rewriter_succ,$rewriter_fails,$rewriter_total" >> $output_file
	local bybmark_out=$out_folder/rewriter_by_benchmark
	# Use a python script for this because it involves some complicated
	# tallying.  But we can apply grep first to keep the size
	# of the inputs down a bit.
	touch $bybmark_out
	../../test/get_results_by_benchmark.sh rewriter_${archname} $data_folder/rewriter.out $bybmark_out

    greedy_succ=$(cat $data_folder/stdout/greedy.out | grep --binary-files=text "^Have" | cut -f2 -d ' ')
    greedy_fails=$(cat $data_folder/stdout/greedy.out | grep --binary-files=text "^Have" | cut -f4 -d ' ')
	greedy_total=$(cat $data_folder/stdout/greedy.out | grep --binary-files=text "^Running over files" | cut -f4 -d ' ')
    echo "Greedy Rewriter,$greedy_succ,$greedy_fails,$greedy_total" >> $output_file
	local bybmark_out=$out_folder/greedy_by_benchmark
	# Use a python script for this because it involves some complicated
	# tallying.  But we can apply grep first to keep the size
	# of the inputs down a bit.
	touch $bybmark_out
	../../test/get_results_by_benchmark.sh greedy_${archname} $data_folder/greedy.out $bybmark_out

    llvm_succ=$(cat $data_folder/stdout/llvm.out | grep --binary-files=text "^Have" | cut -f2 -d ' ')
    llvm_fails=$(cat $data_folder/stdout/llvm.out | grep --binary-files=text "^Have" | cut -f4 -d ' ')
	llvm_total=$(cat $data_folder/stdout/llvm.out | grep --binary-files=text "^Running over files" | cut -f4 -d ' ')
    echo "LLVM Rewriter,$llvm_succ,$llvm_fails,$llvm_total" >> $output_file
	local bybmark_out=$out_folder/llvm_by_benchmark
	# Use a python script for this because it involves some complicated
	# tallying.  But we can apply grep first to keep the size
	# of the inputs down a bit.
	touch $bybmark_out
	../../test/get_results_by_benchmark.sh llvm_${archname} $data_folder/llvm.out $bybmark_out
}

get_rules_applied() {
	# Get a list of the rules applied for each architecture
	local filename=$1/rewriter.out
	local output=$2

	grep --text $filename -e 'applied ' -A1 > $output
}

# Like the above, by don't bother with the results by benchmark, since
# there's enough bars anyway.
get_compile_rates_for_rulesets() {
	local data_folder=$1
	local output_file=$2

	echo -n "" > $output_file

    succ=$(cat ${data_folder}_int/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f2 -d ' ')
    fails=$(cat ${data_folder}_int/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f4 -d ' ')
    total=$(cat ${data_folder}_int/stdout/rewriter.out | grep --binary-files=text "^Running over files" | cut -f4 -d ' ')
    echo "Int Rules,$succ,$fails,$total" >> $output_file

    succ=$(cat ${data_folder}_fp/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f2 -d ' ')
    fails=$(cat ${data_folder}_fp/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f4 -d ' ')
    total=$(cat ${data_folder}_fp/stdout/rewriter.out | grep --binary-files=text "^Running over files" | cut -f4 -d ' ')
    echo "FP Rules,$succ,$fails,$total" >> $output_file

    succ=$(cat ${data_folder}_stochastic/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f2 -d ' ')
    fails=$(cat ${data_folder}_stochastic/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f4 -d ' ')
    total=$(cat ${data_folder}_stochastic/stdout/rewriter.out | grep --binary-files=text "^Running over files" | cut -f4 -d ' ')
    echo "Stochastic Rules,$succ,$fails,$total" >> $output_file

	succ=$(cat ${data_folder}_logic_as_bool/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f2 -d ' ')
	fails=$(cat ${data_folder}_logic_as_bool/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f4 -d ' ')
    total=$(cat ${data_folder}_logic_as_bool/stdout/rewriter.out | grep --binary-files=text "^Running over files" | cut -f4 -d ' ')
    echo "Logic-as-Boolean Rules,$succ,$fails,$total" >> $output_file

    succ=$(cat ${data_folder}_all_rules/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f2 -d ' ')
    fails=$(cat ${data_folder}_all_rules/stdout/rewriter.out | grep --binary-files=text "^Have" | cut -f4 -d ' ')
    total=$(cat ${data_folder}_all_rules/stdout/rewriter.out | grep --binary-files=text "^Running over files" | cut -f4 -d ' ')
    echo "All Rules,$succ,$fails,$total" >> $output_file
}

# These file are built up within each call.  Clear them preemptively
echo -n "" > data/greedy_by_benchmark
echo -n "" > data/rewriter_by_benchmark
echo -n "" > data/no_rules_by_benchmark
echo -n "" > data/llvm_by_benchmark

mkdir -p data
get_compile_rates ../../test/cca_output data/cca CCA data
get_compile_rates ../../test/maeri_output data/maeri Maeri data
get_compile_rates ../../test/revamp_output data/revamp REVAMP data
get_compile_rates ../../test/sc_cgra_output data/sc_cgra SC-CGRA data

# Note that these are not actual folders --- the funciton does some postfixes
# to get the right values out.
get_compile_rates_for_rulesets ../../test/cca_rules data/cca_rules
get_compile_rates_for_rulesets ../../test/maeri_rules data/maeri_rules
get_compile_rates_for_rulesets ../../test/revamp_rules data/revamp_rules
# Note that I typoed the _ into a - for that name.
get_compile_rates_for_rulesets ../../test/sc-cgra_rules data/sc_cgra_rules

if [[ ${#print_used_rules} -gt 0 ]]; then
	# Get the ruleset info
	get_rules_applied ../../test/cca_output_rules_metadata data/cca_applied
	get_rules_applied ../../test/maeri_output_rules_metadata data/maeri_applied
	get_rules_applied ../../test/revamp_output_rules_metadata data/revamp_applied
	get_rules_applied ../../test/sc_cgra_output_rules_metadata data/sc_cgra_applied
fi

# Now plot
python plot_case_studies.py case_studies data/cca data/maeri data/revamp data/sc_cgra

# Also do the by-benchmark plot --- we don't use this here right now, but could do.
python ../../test/plot_successes_by_benchmark.py case_studies_by_benchmark data/no_rules_by_benchmark data/llvm_by_benchmark data/greedy_by_benchmark data/rewriter_by_benchmark --case-studies
python plot_case_studies.py ruleset_studies data/cca_rules data/maeri_rules data/revamp_rules data/sc_cgra_rules

if [[ ${#print_used_rules} -gt 0 ]]; then
	# Now, put the table information into a table
	python generate_rules_table.py data/cca_applied
	python generate_rules_table.py data/maeri_applied
	python generate_rules_table.py data/revamp_applied
	python generate_rules_table.py data/sc_cgra_applied
fi
