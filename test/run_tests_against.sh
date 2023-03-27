#!/bin/zsh

set -eu

typeset use_egraphs use_rewriter use_greedy use_llvm logic_bool_rules int_rules all_rules fp_rules stochastic_rules print_used_rules use_latencies
zparseopts -D -E -use-latencies=use_latencies -use-egraphs=use_egraphs -use-rewriter=use_rewriter -logic-as-bool-rules=logic_bool_rules -fp-rules=fp_rules -int-rules=int_rules -all-rules=all_rules -use-greedy=use_greedy -stochastic-rules=stochastic_rules -print-used-rules=print_used_rules -use-llvm=use_llvm

if [[ $# -ne 4 ]]; then
	echo "Usage: $0 <Reduction Rate> <CGRA Design File> <Other Input Files Base Folder> <Temp Folder>"
	echo "--use-egraphs to use egraph rewriting"
	echo "--use-llvm to use the llvm rewriter"
	echo "--use-greedy to use the greedy rewriter"
	echo "--use-rewriter to use rewriting"
	echo "--use-latencies to use latencies for the A5 (estimated from scheduler)"
	echo "-- other options see the otp of the bash file o--- for controlling what rulesets to use"
	echo "Other files should all be in the format loopX.c (X a number)"
	echo "Reduction rate is the fraction of files to benchmark agains.  Files will be sorted with the gnu sort, then the first <reduction rate> fraction will be used."
	exit 1
fi

temp_folder=$4
rm -rf $temp_folder
mkdir -p $temp_folder
# The location of this should be set to the built libmapper pass.
lmapper=../build/src/libmapperPass.so

original_folder=$PWD
pushd $temp_folder
reduction_rate=$1

## Build the CGRA if this is a CPP file
if [[ $2 == *.cpp ]] || [[ $2 == *.c ]]; then
	echo "Building a CGRA from a CPP file"
	cp $original_folder/$2 kernel.cpp
	echo "Building kernel "
	cat kernel.cpp

	## Build the initial CGRA.
	cp $original_folder/param_example.json param.json #use the param example to build the actual params.
	$original_folder/compile.sh kernel.cpp
	$original_folder/run.sh $original_folder/$lmapper kernel.bc --build
	if [[ ${#use_latencies} -eq 0 ]]; then
		$original_folder/build_param.sh $original_folder/param_skeleton operations.json param.json
	else
		# Use the latencies for the A5 processor (modified to account for pipelining, which obviosuly doens't exist on CGRA ---taken from gcc scheduler for a5.)
		$original_folder/build_param.sh $original_folder/param_skeleton_a5_latencies operations.json param.json
	fi
	timeout=300 # Use 300s timeout --- as we are using small CGRAs for this.
elif [[ "$2" == *.json ]]; then
	echo "Using a pre-specified CGRA"
	# This is a pre-specified architecture --- load the JSON file into here:
	cp $original_folder/$2 param.json
	timeout=600 # Use large timeout because these architectures are much larger, so OpenCGRA is much slower (there's also fewer
	# fewer results to get, so we can use a longer timeout :)
else
	echo "Input file $2 was neither CPP nor a JSON file --- not sure how to create an architecture spec from this"
	exit 1
fi

touch run_output

## Now run over all other input files.
typeset -a files
echo "Looking for files in $original_folder/$3"
for file in $(find $original_folder/$3 -name "*.c" -print0 | sort -z); do
	files+=($file)
done
echo "Before reducing, have ${#files[@]}"
# Do this in python, because it is a bit easier to manage the
# dict of arrays in python.
files=( $(python3 $original_folder/reducer.py --rate $reduction_rate ${files[@]}) )
echo "Running over files ${files[@]}"

extra_flags=""
extra_compile_flags=""
egraphs="false"
if [[ ${#use_egraphs} -gt 0 ]]; then
	extra_flags="$extra_flags --use-egraphs"
	egraphs="true"
fi
if [[ ${#use_greedy} -gt 0 ]]; then
	extra_flags="$extra_flags --use-greedy"
fi
if [[ ${#use_rewriter} -gt 0 ]]; then
	extra_flags="$extra_flags --use-rewriter"
	egraphs="true"
fi
if [[ ${#use_llvm} -gt 0 ]]; then
	extra_compile_flags="$extra_compile_flags --use-llvm-cannonicalizer"
fi
if [[ ${#logic_bool_rules} -gt 0 ]]; then
	extra_flags="$extra_flags --ruleset boolean"
fi
if [[ ${#int_rules} -gt 0 ]]; then
	extra_flags="$extra_flags --ruleset int"
fi
if [[ ${#fp_rules} -gt 0 ]]; then
	extra_flags="$extra_flags --ruleset fp"
fi
if [[ ${#stochastic_rules} -gt 0 ]]; then
	extra_flags="$extra_flags --ruleset stochastic"
fi
if [[ ${#all_rules} -gt 0 ]]; then
	extra_flags="$extra_flags --ruleset boolean --ruleset int --ruleset fp --ruleset stochastic"
fi
if [[ ${#print_used_rules} -gt 0 ]]; then
	extra_flags="$extra_flags --print-used-rules"
fi

parallel "(
	echo 'Starting {}'
	cp {} kernel_{/.}.cpp
	$original_folder/compile.sh $extra_compile_flags kernel_{/.}.cpp
	# A small number seem to cause loops somewhere --- just want to get non-buggy results
	time timeout $timeout $original_folder/run.sh $original_folder/$lmapper kernel_{/.}.bc --params-file $PWD/param.json $extra_flags
	if [[ \$? != 0 ]] && [[ $egraphs == \"true\" ]]; then
		# We timed out, so we should fall back to the mapper without
		# rewriting.  This would ideally happen interally within
		# flex, but it means the same thing happening here :)
		echo 'Rewriter timed out, running without rewriter.'
		# Put a tmeout on this also to avoid infinit e hanging.
		timeout 90 $original_folder/run.sh $original_folder/$lmapper kernel_{/.}.bc --use-rewriter --params-file $PWD/param.json
		if [[ \$? == 124 ]]; then
			echo 'Subrewriter timed out'
		fi
	fi
	echo 'Done Building {/}')" ::: ${files[@]} &> run_output

# Get the successes/fails for each file and print them for further parsing.
# These should be in order, so you get a succ/fail followed by a done that corresponds to it.
grep --text run_output -e "Mapping:success" -e "Mapping:fail" -e "Done File: "

success=$(grep -ce "Mapping:success" run_output || echo "")
fails=$(grep -ce "Mapping:fail" run_output || echo "")

mv run_output run_output.old

echo "Have $success successes, $fails fails"
