#!/bin/zsh

set -eu

typeset use_egraphs use_rewriter logic_bool_rules int_rules all_rules fp_rules
zparseopts -D -E -use-egraphs=use_egraphs -use-rewriter=use_rewriter -logic-as-bool-rules=logic_bool_rules -fp-rules=fp_rules -int-rules=int_rules -all-rules=all_rules

if [[ $# -ne 4 ]]; then
	echo "Usage: $0 <Reduction Rate> <CGRA Design File> <Other Input Files Base Folder> <Temp Folder>"
	echo "--use-egraphs to use egraph rewriting"
	echo "--use-rewriter to use greedy rewriting"
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
	$original_folder/build_param.sh $original_folder/param_skeleton operations.json param.json
	timeout=60 # Use 60s timeout --- as we are using small CGRAs for this.
elif [[ "$2" == *.json ]]; then
	echo "Using a pre-specified CGRA"
	# This is a pre-specified architecture --- load the JSON file into here:
	cp $original_folder/$2 param.json
	timeout=300 # Use large timeout because these architectures are much larger, so OpenCGRA is much slower (there's also fewer
	# results to get, so we can use a longer timeout :)
else
	echo "Input file $2 was neither CPP nor a JSON file --- not sure how to create an architecture spec from this"
	exit 1
fi

touch run_output

## Now run over all other input files.
typeset -a files
echo "Looking for files in $original_folder/$3"
for file in $(find $original_folder/$3 -name "loop*.c" -print0 | sort -z); do
	files+=($file)
done
echo "Before reducing, have ${#files[@]}"
number_to_have=$(( $reduction_rate * ${#files[@]} ))
number_to_have=$((${number_to_have%.*}))
files=( "${files[@]:1:$number_to_have}" )
echo "Running over files ${files[@]}"

extra_flags=""
if [[ ${#use_egraphs} -gt 0 ]]; then
	extra_flags="$extra_flags --use-egraphs"
fi
if [[ ${#use_rewriter} -gt 0 ]]; then
	extra_flags="$extra_flags --use-rewriter"
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
if [[ ${#all_rules} -gt 0 ]]; then
	extra_flags="$extra_flags --ruleset boolean --ruleset int --ruleset fp"
fi

parallel "(
	echo 'Starting {}'
	cp {} kernel_{/.}.cpp
	$original_folder/compile.sh kernel_{/.}.cpp
	# A small number seem to cause loops somewhere --- just want to get non-buggy results
	time timeout $timeout $original_folder/run.sh $original_folder/$lmapper kernel_{/.}.bc --params-file $PWD/param.json $extra_flags
	if [[ \$? == 124 ]]; then
		# We timed out, so we should fall back to the mapper without
		# rewriting.  This would ideally happen interally within
		# flex, but it means the same thing happening here :)
		echo 'Rewriter timed out, running without rewriter.'
		# Put a tmeout on this also to avoid infinit e hanging.
		timeout 50 $original_folder/run.sh $original_folder/$lmapper kernel_{/.}.bc --params-file $PWD/param.json
		if [[ \$? == 124 ]]; then
			echo 'Subrewriter timed out'
		fi
	fi
	echo 'Done Building {/}')" ::: ${files[@]} &> run_output

success=$(grep -ce "Mapping:success" run_output || echo "")
fails=$(grep -ce "Mapping:fail" run_output || echo "")

mv run_output run_output.old

echo "Have $success successes, $fails fails"
