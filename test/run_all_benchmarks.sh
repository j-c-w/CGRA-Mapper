#!/bin/zsh

# This script runs using the rewriter
typeset -a plot_only
zparseopts -D -E -- -plot-only=plot_only

if [[ $# -ne 1 ]]; then
	echo "Usage: $0 benchmarks folder"
	exit 1
fi

folder=$1
target_files=( $(find $1 -name "loop*.c") )

if [[ ${#plot_only} -eq 0 ]]; then
	# Store the stdout of everything to make debugging
	# easier.
	rm -rf run_all_benchmarks_outputs
	mkdir run_all_benchmarks_outputs
	mkdir run_all_benchmarks_outputs/stdout

	for file in ${target_files[@]}; do
		echo "Starting benchmark $file"
		bfile=$(basename $file)
		./run_tests_against.sh $file $folder &> run_all_benchmarks_outputs/stdout/${bfile}.no_rules
		mv run_output.old run_all_benchmarks_outputs/stdout/${bfile}.no_rules.output
		./run_tests_against.sh $file $folder --use-egraphs &> run_all_benchmarks_outputs/stdout/${bfile}.egraphs
		mv run_output.old run_all_benchmarks_outputs/stdout/${bfile}.egraphs.output
		./run_tests_against.sh $file $folder --use-rewriter &> run_all_benchmarks_outputs/stdout/${bfile}.rewriter
		mv run_output.old run_all_benchmarks_outputs/stdout/${bfile}.rewriter.output
	done
fi

# now, create the data files.

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
